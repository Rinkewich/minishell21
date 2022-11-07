/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:05:03 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 20:52:48 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_paths(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
}

char	*find_path_env(char *name, char *envvar)
{
	int		i;
	char	*path;
	char	*to_append;
	char	**paths;

	path = NULL;
	to_append = ft_strjoin("/", name);
	paths = ft_split(envvar, ':');
	i = -1;
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], to_append);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
		path = NULL;
	}
	free(to_append);
	free(envvar);
	free_paths(paths);
	return (path);
}

char	*find_path(t_plit *mini, char *name)
{
	char	*envvar;

	if (access(name, X_OK) == 0)
		return (ft_strdup(name));
	envvar = env_find_val("PATH", mini->env);
	if (envvar)
		return (find_path_env(name, envvar));
	return (NULL);
}
