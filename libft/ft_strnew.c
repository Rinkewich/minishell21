/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:33:32 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 19:48:09 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(int len)
{
	char	*new_word;

	new_word = malloc(sizeof(char) * (len + 1));
	if (!new_word)
		return (NULL);
	new_word[len] = 0;
	return (new_word);
}
