/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:32:02 by fardath           #+#    #+#             */
/*   Updated: 2022/11/07 15:15:23 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	*arrint_new(int len)
{
	int	*tmp;

	tmp = malloc(sizeof(int) * (len + 1));
	tmp[len] = -1;
	return (tmp);
}

int	arrint_len(int *arr)
{
	int	len;

	len = -1;
	while (arr[++len] != -1)
		;
	return (len);
}

int	*arrint_addback(int *old_arr, int new_elem)
{
	int			i;
	int			*tmp;
	const int	new_arrlen = arrint_len(old_arr) + 1;

	tmp = arrint_new(new_arrlen);
	i = -1;
	while (old_arr[++i] != -1)
		tmp[i] = old_arr[i];
	free(old_arr);
	tmp[i] = new_elem;
	return (tmp);
}

void	close_fds(t_command *cmd)
{
	int	i;

	i = -1;
	while (cmd->fdin[++i] != -1)
		close(cmd->fdin[i]);
	i = -1;
	while (cmd->fdout[++i] != -1)
		close(cmd->fdout[i]);
}

t_command	*new_command(char *name, char **argv, int pin, int pout)
{
	t_command	*tmp;

	tmp = malloc(sizeof(t_command) * 1);
	tmp->name = name;
	tmp->argv = argv;
	tmp->fdin = arrint_new(0);
	tmp->fdout = arrint_new(0);
	if (pin != -1)
		tmp->fdin = arrint_addback(tmp->fdin, pin);
	if (pout != -1)
		tmp->fdout = arrint_addback(tmp->fdout, pout);
	return (tmp);
}
