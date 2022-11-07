/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:11:22 by rdeanne           #+#    #+#             */
/*   Updated: 2022/11/07 17:54:02 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wrongarg_error(char *arg)
{
	char	*errormsg;
	char	*tmp;

	errormsg = ft_strjoin("exit: Illegal number: ", arg);
	tmp = errormsg;
	errormsg = ft_strjoin(errormsg, "\n");
	free(tmp);
	if (write(STDERR_FILENO, errormsg, ft_strlen(errormsg)) < 0)
		perror(errormsg);
	free(errormsg);
	g_sigint = 2;
}

void	ft_exit(t_command *cmd)
{
	int		status;

	printf("exit\n");
	if (!cmd->argv[1])
		status = g_sigint;
	else
	{
		status = ft_atoi(cmd->argv[1]);
		if (ft_strlen(cmd->argv[1]) != ft_nbrlen(status)
			|| cmd->argv[1][ft_strlen(cmd->argv[1])] - '0' != status % 10)
		{
			wrongarg_error(cmd->argv[1]);
			return ;
		}
		if (status > 255)
			status %= 256;
		if (status < 0)
			status = 256 + (status % 256);
	}
	exit(status);
}
