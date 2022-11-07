/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:04:12 by fardath           #+#    #+#             */
/*   Updated: 2021/10/18 16:04:18 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	if (dstsize > ft_strlen(dst))
		k = ft_strlen(dst) + ft_strlen(src);
	else
		k = dstsize + ft_strlen(src);
	i = ft_strlen(dst);
	j = 0;
	while ((src[j] != '\0') && ((i + 1) < dstsize))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (k);
}
