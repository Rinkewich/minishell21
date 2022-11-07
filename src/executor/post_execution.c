/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 02:53:47 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 18:11:23 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	post_execution(t_plit *mini)
{
	clear_tokens(*mini->tokens);
	free(mini->tokens);
	mini->tokens = NULL;
}
