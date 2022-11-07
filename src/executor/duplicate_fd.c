/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:49:27 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 18:11:49 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	duplicate_fdout(int *fdout)
{
	int	i;

	i = -1;
	while (fdout[++i] != -1)
	{
		dup2(fdout[i], STDOUT_FILENO);
		close(fdout[i]);
	}
}

void	duplicate_fdin(int *fdin)
{
	int	i;

	i = -1;
	while (fdin[++i] != -1)
	{
		dup2(fdin[i], STDIN_FILENO);
		close(fdin[i]);
	}
}
