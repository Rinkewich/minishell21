/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:38:43 by fardath           #+#    #+#             */
/*   Updated: 2022/11/07 18:00:58 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_split_data	*init_split_data(char *line)
{
	t_split_data	*data;

	data = malloc(sizeof(t_split_data));
	data->index = 0;
	data->line = line;
	data->words = ft_arrnew(0);
	return (data);
}

void	spliter(t_plit *split)
{
	t_split_data	*data;

	data = init_split_data(split->line);
	while (check_letter(data))
	{
		if (check_separator(data))
			put_separator(data);
		else if (check_quote(data))
			put_quote(data);
		else
			put_word(data);
	}
	free(split->split_line);
	split->split_line = data->words;
	free(data);
}
