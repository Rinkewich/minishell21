/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:56:45 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 19:42:57 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_word(t_parser *data)
{
	return (data->words[data->index]);
}

int	command_set(t_parser *data)
{
	return (data->command_is_set);
}

char	*remove_quotes(char *word)
{
	int		i;
	int		len;
	char	*result;

	len = ft_strlen(word) - 2;
	result = ft_strnew(len - 2);
	i = -1;
	while (++i < len)
		result[i] = word[i + 1];
	free(word);
	return (result);
}

void	add_to_argv(t_parser *data)
{
	char	*arg;
	char	**argv;

	argv = data->current_command->argv;
	arg = ft_strdup(check_word(data));
	if (ft_strchr("\'\"", arg[0])
		&& ft_strchr("\'\"", arg[ft_strlen(arg) - 1])
		&& arg[ft_strlen(arg) - 1] == arg[0])
		arg = remove_quotes(arg);
	argv = ft_arr_addback(argv, arg);
	data->current_command->argv = argv;
	data->index++;
}
