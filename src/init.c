/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:21:03 by rdeanne           #+#    #+#             */
/*   Updated: 2022/10/07 12:41:14 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(t_shell *shell)
{
	shell->exit_flag = 0;
	shell->exit_status = 0;
	shell->env_list = NULL;
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
	shell->env_list = delete_env(shell->env_list, "OLDPWD");
}
