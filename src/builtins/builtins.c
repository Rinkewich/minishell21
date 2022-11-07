/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 10:23:41 by dgizzard          #+#    #+#             */
/*   Updated: 2022/11/06 18:09:32 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_builtin(char	*name)
{
	int			i;
	const char	*builtins[] = {"echo", "cd", "pwd", "export",
		"unset", "env", "exit"};

	i = 0;
	while (i < 7)
	{
		if (ft_strlen(builtins[i]) == ft_strlen(name)
			&& ft_strncmp(name, builtins[i], ft_strlen(name)) == 0)
			return (1);
		i++;
	}
	return (0);
}
