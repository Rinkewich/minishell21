/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:15:19 by rdeanne           #+#    #+#             */
/*   Updated: 2022/09/15 13:24:18 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token(char *val, int type)
{
	t_token	*head;

	head = malloc(sizeof(t_token));
	if (!head)
		return (NULL);
	head->val = val;
	head->type = type;
	head->prev = head;
	head->next = head;
	return (head);
}

t_token	*push_token(t_token *head, char *val, int type)
{
	t_token	*new;

	if (!head)
		return (create_list(val, type));
	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->val = val;
	new->type = type;
	new->next = head;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
	return (new);
}

void	delete_tokens(t_token **head)
{
	t_token	*tmp_list;

	if (!*head)
		return ;
	tmp_list = *head;
	free(tmp_list->val);
	free(tmp_list);
	tmp_list = tmp_list->next;
	while (tmp_list != *head)
	{
		free(tmp_list->val);
		free(tmp_list);
		tmp_list = tmp_list->next;
	}
	*head = NULL;
}
