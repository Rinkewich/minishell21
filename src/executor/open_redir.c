/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:55:17 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 20:52:43 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_heredoc(char *filename, t_command *cmd)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(filename);
		exit(127);
	}
	cmd->fdin = arrint_addback(cmd->fdin, fd);
}

void	open_redirin(char *filename, t_command *cmd)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror(filename);
		exit(127);
	}
	cmd->fdin = arrint_addback(cmd->fdin, fd);
}

void	open_redirout(char *filename, t_command *cmd)
{
	int	fd;

	fd = open(filename, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(filename);
		exit(127);
	}
	cmd->fdout = arrint_addback(cmd->fdout, fd);
}

void	open_redirout_a(char *filename, t_command *cmd)
{
	int	fd;

	fd = open(filename, O_APPEND | O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(filename);
		exit(127);
	}
	cmd->fdout = arrint_addback(cmd->fdout, fd);
}

void	open_redir(t_token	*current, t_command *cmd)
{
	if (current->type == Heredoc)
		open_heredoc(current->argv[1], cmd);
	else if (current->type == Redirin)
		open_redirin(current->argv[1], cmd);
	else if (current->type == Redirout)
		open_redirout(current->argv[1], cmd);
	else if (current->type == Redirout_a)
		open_redirout_a(current->argv[1], cmd);
}
