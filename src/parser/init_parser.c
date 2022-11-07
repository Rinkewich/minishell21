/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:34:15 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 19:43:05 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parser	*init_parser(char **split)
{
	t_parser	*parser;

	parser = malloc(sizeof(t_parser) * 1);
	parser->command_is_set = 0;
	parser->current_command = NULL;
	parser->head = malloc(sizeof(t_token *) * 1);
	*parser->head = NULL;
	parser->index = 0;
	parser->words = split;
	return (parser);
}
