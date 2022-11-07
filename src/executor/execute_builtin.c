/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 02:58:27 by fardath           #+#    #+#             */
/*   Updated: 2022/11/07 11:37:27 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_builtin(t_plit *mini, t_command *cmd)
{
	if (ft_strncmp(cmd->name, "echo", ft_strlen("echo")) == 0)
		ft_echo(cmd->argv);
	if (ft_strncmp(cmd->name, "cd", ft_strlen("cd")) == 0)
		ft_cd(cmd->argv, mini->env);
	if (ft_strncmp(cmd->name, "env", ft_strlen("env")) == 0)
		mini_env(mini);
	if (ft_strncmp(cmd->name, "pwd", ft_strlen("pwd")) == 0)
		mini_pwd();
	if (ft_strncmp(cmd->name, "exit", ft_strlen("exit")) == 0)
		mini_exit(cmd);
	if (ft_strncmp(cmd->name, "unset", ft_strlen("unset")) == 0)
		mini->env = mini_unset(cmd->argv, mini->env);
	if (ft_strncmp(cmd->name, "export", ft_strlen("export")) == 0)
		mini->env = mini_export(cmd->argv, mini->env, mini);
}
