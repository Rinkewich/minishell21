/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:49:13 by rdeanne           #+#    #+#             */
/*   Updated: 2022/06/14 13:23:34 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_cmd_path(char *cmd, char *path_env)
{
	char			**bin;
	int				i;
	DIR				*folder;
	struct dirent	*file;

	bin = ft_split(path_env, ':');
	i = 0;
	while (bin[i])
	{
		folder = opendir(bin[i]);
		if (!folder)
			return (NULL);
		file = readdir(folder);
		while (file)
		{
			if (ft_strcmp(file->d_name, cmd) == 0)
			{
				closedir(folder);
				return (ft_strjoin(ft_strjoin(bin[i], "/"), cmd));
			}
			file = readdir(folder);
		}
		closedir(folder);
		i++;
	}
	return (NULL);
}

int	exec_cmd(char *cmd, char **argv, char **envp, t_shell *shell)
{
	char	*cmd_path;
	char	*path_env;
	pid_t	pid;

	path_env = get_list(shell->env_list, "PATH")->val;
	if (!path_env)
		return (1);
	cmd_path = find_cmd_path(cmd, path_env);
	if (!cmd_path)
		return (1);
	pid = fork();
	if (pid == 0)
		execve(cmd_path, argv, envp);
	else
		waitpid(pid, NULL, 0);
	return (0);
}