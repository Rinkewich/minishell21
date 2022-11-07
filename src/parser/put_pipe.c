/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:32:50 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 19:42:07 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_pipe(t_parser *data)
{
	t_token	*pipe;

	pipe = new_token(check_word(data), Pipe);
	token_push_back(data->head, pipe);
	data->current_command = NULL;
	data->command_is_set = 0;
	data->index++;
}
