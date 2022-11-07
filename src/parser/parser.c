/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:26:01 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 19:42:22 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(t_plit *split)
{
	t_parser	*data;

	data = init_parser(split->split_line);
	while (check_word(data))
	{
		if (find_redirect(data))
			put_redirect(split, data);
		else if (find_pipe(data))
			put_pipe(data);
		else if (command_set(data))
			add_to_argv(data);
		else
			put_command(data);
	}
	split->tokens = data->head;
	free(data);
}
