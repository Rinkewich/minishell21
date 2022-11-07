/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:26:57 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 19:48:40 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrnew(int len)
{
	char	**new_words;

	new_words = malloc(sizeof(char *) * (len + 1));
	if (!new_words)
		return (NULL);
	new_words[len] = NULL;
	return (new_words);
}
