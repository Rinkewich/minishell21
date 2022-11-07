/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:41:45 by rdeanne           #+#    #+#             */
/*   Updated: 2022/04/12 14:51:49 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_inset(char c, char const *set)
{
	int	count;

	count = 0;
	if (!set)
		return (0);
	while (set[count])
	{
		if (c == set[count])
			return (1);
		count++;
	}
	return (0);
}
