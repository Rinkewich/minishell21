/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:51:24 by rdeanne           #+#    #+#             */
/*   Updated: 2022/11/07 15:52:02 by rdeanne          ###   ########.fr       */
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

char	*cd_minus(t_list *envp)
{
	char	*res;

	if (!get_list(envp, "OLDPWD"))
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set\n", STDERR);
		return (NULL);
	}
	res = get_list(envp, "OLDPWD")->val;
	printf("%s\n", res);
	return (res);
}

int	ft_cd(char *path, t_list *envp)
{
	char	dir[MAX_PATH];
	char	*pwd;

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
		return (ft_cd(cd_minus(envp), envp));
	envp = update_list(envp, ft_strndup("OLDPWD", 6), pwd);
	if (!getcwd(dir, MAX_PATH))
		return (3);
	pwd = ft_strndup(dir, ft_strlen(dir));
	envp = update_list(envp, ft_strndup("PWD", 3), pwd);
	return (0);
}
