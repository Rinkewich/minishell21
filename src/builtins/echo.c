/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:14:54 by rdeanne           #+#    #+#             */
/*   Updated: 2022/11/07 17:54:14 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_command *cmd)
{
	int		i;
	char	*new_line;

	i = 0;
	new_line = "\n";
	if (cmd->argv[1]
		&& ft_strlen(cmd->argv[1]) == 2
		&& ft_strncmp(cmd->argv[1], "-n", 2) == 0)
	{
		++i;
		new_line = "";
	}
	while (cmd->argv[++i])
	{
		printf("%s", cmd->argv[i]);
		if (cmd->argv[i + 1])
			printf(" ");
	}
	printf("%s", new_line);
	g_sigint = 0;
}
