/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 02:55:32 by fardath           #+#    #+#             */
/*   Updated: 2022/11/07 18:02:33 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/stat.h>

void	execute_bin(t_plit *mini, t_command *cmd, char *path)
{
	char	**envp;

	envp = list_to_arrchar(mini->env);
	duplicate_fdout(cmd->fdout);
	duplicate_fdin(cmd->fdin);
	if (execve(path, cmd->argv, envp) == -1)
		perror(NULL);
	while (!(*envp))
	{
		free(*envp);
		(*envp)++;
	}
	free(envp);
	free(path);
}

int	is_regular_file(const char *path)
{
	struct stat	statbuf;

	stat(path, &statbuf);
	return (S_ISREG(statbuf.st_mode));
}

void	execute_command(t_plit *mini, t_command *cmd)
{
	char	*path;
	char	*errormsg;

	path = find_path(mini, cmd->name);
	if (path && is_regular_file(path))
		execute_bin(mini, cmd, path);
	else
	{
		if (path)
		{
			free(path);
			errormsg = ft_strjoin(cmd->name, ": Is a directory\n");
		}
		else
			errormsg = ft_strjoin(cmd->name, ": command not found\n");
		if (write(STDERR_FILENO, errormsg, ft_strlen(errormsg)) < 0)
			perror(errormsg);
		free(errormsg);
		exit(127);
	}
}
