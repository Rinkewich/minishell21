/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:05:03 by fardath           #+#    #+#             */
/*   Updated: 2022/11/07 15:17:43 by rdeanne          ###   ########.fr       */
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
	t_list	*tmp_env;

	if (access(name, X_OK) == 0)
		return (ft_strdup(name));
	tmp_env = get_list(mini->env, "PATH");
	if (tmp_env)
		return (find_path_env(name, tmp_env->val));
	return (NULL);
}
