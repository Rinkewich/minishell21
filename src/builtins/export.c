/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:45:49 by rdeanne           #+#    #+#             */
/*   Updated: 2022/06/08 16:52:36 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_env(char *str)
{
	if (!str || str[0] == '\0')
		return (0);
	return (1);
}

int	ft_export(t_shell *shell, char	*str)
{
	char	**env_str;
	t_list	*sorted_list;

	sorted_list = NULL;
	if (!str || str[0] == '\0')
	{
		sorted_list = copy_list(shell->env_list);
		sorted_list = delete_env(sorted_list, "_");
		print_export_list(sort_list(sorted_list));
		delete_list(&sorted_list);
		return (0);
	}
	if (!check_env(str))
	{
		ft_putendl_fd("export: not an identifier: 34", 2);
		return (1);
	}
	env_str = parse_env_str(str);
	shell->env_list = update_list(shell->env_list, env_str[0], env_str[1]);
	free(env_str);
	shell->env_list = swap_down(shell->env_list);
	return (0);
}
