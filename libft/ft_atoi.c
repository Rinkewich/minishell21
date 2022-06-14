/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:41:52 by rdeanne           #+#    #+#             */
/*   Updated: 2022/04/12 14:51:28 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || \
		c == '\v' || c == '\f' || \
		c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	res;
	unsigned long	max;
	int				sign;

	sign = 1;
	res = 0;
	max = 922337203685477580;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		if ((res > max || (res == max && (*str - '0') > 7)) && sign == 1)
			return (-1);
		if ((res > max || (res == max && (*str - '0') > 8)) && sign == -1)
			return (0);
		res = res * 10 + (*str++ - '0');
	}
	return ((int)(sign * res));
}
