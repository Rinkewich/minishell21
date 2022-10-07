/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:51:24 by rdeanne           #+#    #+#             */
/*   Updated: 2022/10/07 14:04:04 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//  Надо сделать "cd -" "cd"

int	ft_cd(const char *path, t_list *envp)
{
	char	*error;
	char	dir[MAX_PATH];
	char	*pwd;
	char	*key;
	char	*tmp_pwd;

	if (!path)
		return (ft_cd(get_list(envp, "HOME")->val, envp));
	if (!getcwd(dir, MAX_PATH))
		return (3);
	pwd = ft_strndup(dir, ft_strlen(dir));
	if (chdir(path) == -1 && ft_strcmp(path, "-"))
	{
		error = ft_strtolower(strerror(errno));
		ft_putstr_fd("cd: ", STDERR);
		ft_putstr_fd(error, STDERR);
		ft_putstr_fd(": ", STDERR);
		ft_putendl_fd(path, STDERR);
		free(error);
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
	key = ft_strndup("OLDPWD", 6);
	envp = update_list(envp, key, pwd);
	if (!getcwd(dir, MAX_PATH))
		return (3);
	pwd = ft_strndup(dir, ft_strlen(dir));
	key = ft_strndup("PWD", 3);
	envp = update_list(envp, key, pwd);
	return (0);
}
