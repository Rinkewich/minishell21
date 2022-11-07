/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 21:12:46 by fardath           #+#    #+#             */
/*   Updated: 2021/10/18 21:43:50 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*scp;

	scp = (char *)malloc(ft_strlen(s1) + 1);
	if (scp == NULL)
		return (NULL);
	ft_memcpy(scp, s1, ft_strlen(s1) + 1);
	return (scp);
}
