/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:21:03 by rdeanne           #+#    #+#             */
/*   Updated: 2022/11/07 14:46:43 by rdeanne          ###   ########.fr       */
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
