/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:51:24 by rdeanne           #+#    #+#             */
/*   Updated: 2022/10/05 12:59:51 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//  Надо сделать "cd -" "cd"

int	ft_cd(const char *path)
{
	char	*error;

	if (!path)
		return (1);
	if (chdir(path) == -1)
	{
		error = ft_strtolower(strerror(errno));
		ft_putstr_fd("cd: ", STDERR);
		ft_putstr_fd(error, STDERR);
		ft_putstr_fd(": ", STDERR);
		ft_putendl_fd(path, STDERR);
		free(error);
		return (2);
	}
	return (0);
}
