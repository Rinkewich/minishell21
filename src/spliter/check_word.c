/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:13:30 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 20:51:47 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	put_word(t_split_data *data)
{
	char	*word;

	word = ft_strnew(0);
	while (check_letter(data) && check_separator(data) == 0)
	{
		word = ft_str_addletter(word, check_letter(data));
		data->index++;
	}
		data->words = ft_arr_addback(data->words, word);
}
