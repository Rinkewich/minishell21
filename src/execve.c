/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:49:13 by rdeanne           #+#    #+#             */
/*   Updated: 2022/11/01 10:13:52 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_cmd_path(char *cmd, char **bin)
{
	int				i;
	DIR				*folder;
	struct dirent	*file;

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

int	exec_cmd(char **argv, char **envp, t_shell *shell)
{
	char	*cmd_path;
	char	*path_env;
	t_list	*tmp_list;
	pid_t	pid;

	tmp_list = get_list(shell->env_list, "PATH");
	if (!tmp_list)
		return (1);
	path_env = tmp_list->val;
	cmd_path = find_cmd_path(argv[0], ft_split(path_env, ':'));
	if (!cmd_path)
	{
		ft_putstr_fd("minishell: ", STDERR);
		ft_putstr_fd(argv[0], STDERR);
		ft_putstr_fd(": command not found\n", STDERR);
		return (1);
	}
	pid = fork();
	if (pid == 0)
		execve(cmd_path, argv, envp);
	else
		waitpid(pid, NULL, 0);
	free(cmd_path);
	return (0);
}

int	exec_builtin(char **argv, t_shell *shell)
{
	char	*cmd;

	cmd = argv[0];
	if (!ft_strcmp(cmd, "cd"))
		return (ft_cd(argv[1], shell->env_list));
	if (!ft_strcmp(cmd, "echo"))
		return (ft_echo(argv));
	if (!ft_strcmp(cmd, "env"))
		return (ft_env(shell));
	if (!ft_strcmp(cmd, "exit"))
		return (ft_exit(shell));
	if (!ft_strcmp(cmd, "export"))
		return (ft_export(shell, argv[1]));
	if (!ft_strcmp(cmd, "pwd"))
		return (ft_pwd());
	if (!ft_strcmp(cmd, "unset"))
		return (ft_unset(shell, argv[1]));
	return (0);
}
