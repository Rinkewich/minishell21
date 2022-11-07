/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_addletter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:15:43 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 19:48:23 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_addletter(char *old_word, char letter)
{
	int			i;
	char		*new_word;
	const int	new_wordlen = (ft_strlen(old_word) + 1);

	new_word = ft_strnew(new_wordlen);
	if (!new_word)
		return (NULL);
	i = -1;
	while (old_word[++i])
		new_word[i] = old_word[i];
	new_word[i] = letter;
	free(old_word);
	return (new_word);
}
