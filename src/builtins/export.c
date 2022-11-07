/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:45:49 by rdeanne           #+#    #+#             */
/*   Updated: 2022/11/07 17:58:42 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_env(char *str)
{
	if (ft_isdigit(str[0]))
	{
		ft_putstr_fd("minishell: export: `", STDERR);
		ft_putstr_fd(str, STDERR);
		ft_putendl_fd("': not a valid identifier", STDERR);
		return (0);
	}
	return (1);
}

int	ft_export(t_plit *shell, char **argv)
{
	char	**env_str;
	char	*str;
	t_list	*sorted_list;

	str = argv[1];
	sorted_list = NULL;
	if (!str || str[0] == '\0')
	{
		sorted_list = copy_list(shell->env);
		sorted_list = delete_env(sorted_list, "_");
		print_export_list(sort_list(sorted_list));
		delete_list(&sorted_list);
		return (0);
	}
	if (!check_env(str))
		return (1);
	if (ft_chrpos(str, '=') == -1)
		return (0);
	env_str = parse_env_str(str);
	shell->env = update_list(shell->env, env_str[0], env_str[1]);
	free(env_str);
	shell->env = swap_down(shell->env);
	return (0);
}
