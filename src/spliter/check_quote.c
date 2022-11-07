/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:03:14 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 20:51:55 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quote(t_split_data *data)
{
	char	c;

	c = check_letter(data);
	if (c == QUOTES_D || c == QUOTES_S)
		return (1);
	return (0);
}

void	put_quote(t_split_data *data)
{
	char	*word;
	char	quoute;

	quoute = check_letter(data);
	word = ft_strnew(1);
	word[0] = quoute;
	data->index++;
	while (check_letter(data) && check_letter(data) != quoute)
	{
		word = ft_str_addletter(word, check_letter(data));
		data->index++;
	}
	if (check_letter(data) == quoute)
		word = ft_str_addletter(word, quoute);
	data->words = ft_arr_addback(data->words, word);
	data->index++;
}
