/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:27:18 by rdeanne           #+#    #+#             */
/*   Updated: 2022/10/19 16:21:03 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**parse_env_str(char *str)
{
	char	**res;
	int		eqlpos;

	res = malloc(sizeof(char *) * 2);
	eqlpos = ft_chrpos(str, '=');
	res[0] = ft_strndup(str, eqlpos);
	res[1] = ft_strndup(ft_strchr(str, '=') + 1, ft_strlen(str) - eqlpos - 1);
	return (res);
}

int	ft_env(t_shell *shell)
{
	if (!shell->env_list)
		return (0);
	print_list(shell->env_list);
	return (0);
}
