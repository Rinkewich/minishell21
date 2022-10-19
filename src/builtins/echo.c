/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:14:54 by rdeanne           #+#    #+#             */
/*   Updated: 2022/10/19 15:48:50 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **argv)
{
	int	i;
	int	n_flag;

	i = 0;
	n_flag = 0;
	if (!argv)
		return (1);
	if (argv[i + 1] && !ft_strcmp(argv[i + 1], "-n"))
	{
		n_flag = 1;
		i++;
	}
	if (argv[++i])
	{
		write(STDOUT, argv[i], ft_strlen(argv[i]));
		while (argv[i])
		{
			write(STDOUT, " ", 1);
			write(STDOUT, argv[i], ft_strlen(argv[i]));
			i++;
		}
	}
	if (!n_flag)
		write(STDOUT, "\n", 1);
	return (0);
}
