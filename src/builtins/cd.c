/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:51:24 by rdeanne           #+#    #+#             */
/*   Updated: 2022/10/19 15:46:16 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_cd_error(const char *path)
{
	char	*error;

	error = ft_strtolower(strerror(errno));
	ft_putstr_fd("cd: ", STDERR);
	ft_putstr_fd(error, STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putendl_fd(path, STDERR);
	free(error);
}

int	ft_cd(const char *path, t_list *envp)
{
	char	dir[MAX_PATH];
	char	*pwd;
	char	*tmp_pwd;

	if (!path)
		return (ft_cd(get_list(envp, "HOME")->val, envp));
	if (!getcwd(dir, MAX_PATH))
		return (3);
	pwd = ft_strndup(dir, ft_strlen(dir));
	if (chdir(path) == -1 && ft_strcmp(path, "-"))
	{
		print_cd_error(path);
		free(pwd);
		return (2);
	}
	else if (!ft_strcmp(path, "-"))
	{
		if (!get_list(envp, "OLDPWD"))
		{
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", STDERR);
			return (4);
		}
		tmp_pwd = get_list(envp, "OLDPWD")->val;
		printf("%s\n", tmp_pwd);
		return (ft_cd(tmp_pwd, envp));
	}
	envp = update_list(envp, ft_strndup("OLDPWD", 6), pwd);
	if (!getcwd(dir, MAX_PATH))
		return (3);
	pwd = ft_strndup(dir, ft_strlen(dir));
	envp = update_list(envp, ft_strndup("PWD", 3), pwd);
	return (0);
}
