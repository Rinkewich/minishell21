/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:28:36 by rdeanne           #+#    #+#             */
/*   Updated: 2022/10/19 16:21:38 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_output(t_shell *shell, t_token *token, int type)
{
	ft_close(shell->fdout);
	if (type == REDIR_OUTPUT)
		shell->fdout = open(token->val, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	else
		shell->fdout = open(token->val, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
	if (shell->fdout == -1)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(token->val, STDERR);
		ft_putendl_fd(": No such file or directory", STDERR);
		shell->exit_status = 1;
		return ;
	}
	dup2(shell->fdout, STDOUT);
}

void	redir_input(t_shell *shell, t_token *token)
{
	ft_close(shell->fdin);
	shell->fdin = open(token->val, O_RDONLY, S_IRWXU);
	if (shell->fdin == -1)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(token->val, STDERR);
		ft_putendl_fd(": No such file or directory", STDERR);
		shell->exit_status = 1;
		return ;
	}
	dup2(shell->fdin, STDIN);
}

void	reset_std(t_shell *shell)
{
	dup2(shell->fdin, STDIN);
	dup2(shell->fdout, STDOUT);
}
