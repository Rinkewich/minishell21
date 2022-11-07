/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:10:13 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 19:48:45 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arr_addback(char **old_array, char *word)
{
	int			i;
	char		**new_array;
	const int	new_arrlen = (ft_arrlen(old_array) + 1);

	new_array = ft_arrnew(new_arrlen);
	if (!new_array)
		return (NULL);
	i = -1;
	while (old_array[++i])
		new_array[i] = old_array[i];
	new_array[i] = word;
	free(old_array);
	return (new_array);
}
