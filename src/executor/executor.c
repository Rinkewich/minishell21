/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:22:01 by fardath           #+#    #+#             */
/*   Updated: 2022/11/07 17:28:15 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tokens_has_pipe(t_token *token)
{
	while (token)
	{
		if (token->type == Pipe)
			return (1);
		token = token->next;
	}
	return (0);
}

int	tokens_has_builtin(t_token *token)
{
	while (token)
	{
		if (is_builtin(token->val))
			return (1);
		token = token->next;
	}
	return (0);
}

void	executor_builtin(t_plit	*mini)
{
	t_command	*cmd;
	t_token		*current;

	cmd = new_command(NULL, NULL, -1, -1);
	current = *mini->tokens;
	while (current)
	{
		if (current->type == Command)
		{
			cmd->name = current->val;
			cmd->argv = current->argv;
		}
		current = current->next;
	}
	execute_builtin(mini, cmd);
}

void	execute(t_plit *mini)
{
	if (tokens_has_builtin(*mini->tokens) || tokens_has_pipe(*mini->tokens))
		executor_builtin(mini);
	else
		execute_bins(mini);
	post_execution(mini);
}
