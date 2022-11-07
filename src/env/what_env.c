/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:12:09 by fardath           #+#    #+#             */
/*   Updated: 2022/11/07 17:53:43 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_envvar(t_list *env, char *result, char *line)
{
	t_list	*tmp_list;
	char	*tmp_str;

	tmp_list = get_list(env, line);
	if (!tmp_list)
		return (result);
	tmp_str = ft_strjoin(result, tmp_list->val);
	free(result);
	return (tmp_str);
}

int	shift_to_separator(char *str)
{
	int	j;

	j = -1;
	while (str[++j]
		&& !ft_strchr(SEPARATORS, str[j]))
		;
	return (j);
}

void	what_env(t_plit *split, int sq, int dq, int i)
{
	int			j;
	char		*result;

	result = ft_strnew(0);
	while (split->line[i])
	{
		while (split->line[i] && (split->line[i] != '$' || sq))
		{
			if (!dq && split->line[i] == '\'')
				sq = 1 - sq;
			if (!sq && split->line[i] == '\"')
				dq = 1 - dq;
			result = ft_str_addletter(result, split->line[i]);
			i++;
		}
		if (split->line[i] == '$')
		{
			j = shift_to_separator(split->line + ++i);
			result = join_envvar(split->env, result, split->line + i);
			i = i + j;
		}
	}
	free(split->line);
	split->line = result;
}
