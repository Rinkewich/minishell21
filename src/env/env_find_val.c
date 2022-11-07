/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_find_val.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:05:22 by fardath           #+#    #+#             */
/*   Updated: 2022/11/07 17:53:35 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_find_val(char *val, t_list *env)
{
	t_list	*tmp_env;
	char	*result;

	if (ft_strlen(val) == 1 && val[0] == '?')
	{
		result = ft_itoa(g_sigint);
		return (result);
	}
	tmp_env = get_list(env, val);
	result = ft_strdup(tmp_env->val);
	return (result);
}
