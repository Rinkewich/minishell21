/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:08:29 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 19:43:55 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_pipe(t_parser *data)
{
	char	*word;

	word = check_word(data);
	if (ft_strlen(word) == ft_strlen(PIPE)
		&& ft_strncmp(word, PIPE, ft_strlen(PIPE)) == 0)
		return (1);
	return (0);
}
