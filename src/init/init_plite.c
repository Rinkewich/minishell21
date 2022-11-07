/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:35:25 by fardath           #+#    #+#             */
/*   Updated: 2022/11/07 17:55:28 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	inc_shlvl(t_list *env)
{
	int	prev_shlvl;

	if (!env)
		return ;
	prev_shlvl = ft_atoi(get_list(env, "SHLVL")->val);
	env = update_list(env, "SHLVL", ft_itoa(prev_shlvl + 1));
}

void	init_env(t_plit *shell, char **envp)
{
	int		i;
	char	**env_str;

	i = 0;
	shell->env = NULL;
	while (envp[i])
	{
		env_str = parse_env_str(envp[i]);
		shell->env = rotate_list(push_list(\
			shell->env, env_str[0], env_str[1]));
		free(env_str);
		i++;
	}
	shell->env = delete_env(shell->env, "OLDPWD");
	inc_shlvl(shell->env);
}

t_plit	*init_plit(int argc, char **argv, char **env)
{
	t_plit	*split;

	split = malloc(sizeof(t_plit));
	split->pid = getpid();
	split->argv = argv;
	split->argc = argc;
	split->temporary = 0;
	init_env(split, env);
	return (split);
}
