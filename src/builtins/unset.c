/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:50:31 by rdeanne           #+#    #+#             */
/*   Updated: 2022/11/07 15:57:55 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(t_plit *shell, char **argv)
{
	char	*key;

	key = argv[1];
	shell->env = delete_env(shell->env, key);
	return (0);
}
