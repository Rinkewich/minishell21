/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:32:47 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 19:42:15 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_command(t_parser *data)
{
	char	*name;
	t_token	*command_token;

	name = ft_strdup(check_word(data));
	if (ft_strchr("\'\"", name[0])
		&& ft_strchr("\'\"", name[ft_strlen(name)-1])
		&& name[0] == name[ft_strlen(name)-1])
		name = remove_quotes(name);
	command_token = new_token(name, Command);
	token_push_back(data->head, command_token);
	data->current_command = command_token;
	data->command_is_set = 1;
	data->index++;
}
