/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:01:59 by rdeanne           #+#    #+#             */
/*   Updated: 2022/10/19 16:00:09 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*create_list(char *key, char *val)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->key = key;
	head->val = val;
	head->prev = head;
	head->next = head;
	return (head);
}

t_list	*push_list(t_list *head, char *key, char *val)
{
	t_list	*new;

	if (!head)
		return (create_list(key, val));
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->key = key;
	new->val = val;
	new->next = head;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
	return (new);
}

t_list	*update_list(t_list *head, char *key, char *val)
{
	t_list	*begin;

	begin = head;
	if (!head)
		return (create_list(key, val));
	if (!ft_strcmp(head->key, key))
	{
		free(head->val);
		head->val = val;
		return (begin);
	}
	head = head->next;
	while (head != begin)
	{
		if (!ft_strcmp(head->key, key))
		{
			free(head->val);
			head->val = val;
			return (begin);
		}
		head = head->next;
	}
	return (swap_down(rotate_list(push_list(begin, key, val))));
}

t_list	*pop_list(t_list *head)
{
	t_list	*prev;
	t_list	*next;

	if (!head)
		return (NULL);
	if (head == head->next)
	{
		free(head->val);
		free(head->key);
		free(head);
		return (NULL);
	}
	next = head->next;
	prev = head->prev;
	prev->next = head->next;
	next->prev = head->prev;
	free(head->val);
	free(head->key);
	free(head);
	return (next);
}

void	delete_list(t_list **head)
{
	t_list	*tmp_list;

	if (!*head)
		return ;
	tmp_list = *head;
	free(tmp_list->key);
	free(tmp_list->val);
	free(tmp_list);
	tmp_list = tmp_list->next;
	while (tmp_list != *head)
	{
		free(tmp_list->key);
		free(tmp_list->val);
		free(tmp_list);
		tmp_list = tmp_list->next;
	}
	*head = NULL;
}
