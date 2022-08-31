/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:21:03 by rdeanne           #+#    #+#             */
/*   Updated: 2022/06/08 16:53:05 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(t_shell *shell)
{
	shell->exit_flag = 0;
	shell->env_list = NULL;
	g_sig.sigint = 0;
	g_sig.sigquit = 0;
}

void	init_env(t_shell *shell, char **envp)
{
	int		i;
	char	**env_str;

	i = 0;
	shell->env_list = NULL;
	while (envp[i])
	{
		env_str = parse_env_str(envp[i]);
		shell->env_list = rotate_list(push_list(shell->env_list, env_str[0], env_str[1]));
		free(env_str);
		i++;
	}
	// update_env(shell->env, env);
	// print_list(env);
}
