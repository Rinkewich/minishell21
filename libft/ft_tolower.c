/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:47:34 by rdeanne           #+#    #+#             */
/*   Updated: 2022/06/03 11:55:35 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		c += 32;
	return (c);
}

char	*ft_strtolower(const char *str)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char) * ft_strlen(str));
	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		res[i] = ft_tolower(str[i]);
		i++;
	}
	return (res);
}
