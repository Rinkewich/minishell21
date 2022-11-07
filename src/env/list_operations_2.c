/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:03:55 by rdeanne           #+#    #+#             */
/*   Updated: 2022/11/07 15:41:48 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*rotate_list(t_list *head)
{
	if (!head)
		return (NULL);
	return (head->next);
}

t_list	*reverse_rotate_list(t_list *head)
{
	if (!head)
		return (NULL);
	return (head->prev);
}

t_list	*swap_top(t_list *head)
{
	t_list	*prev;
	t_list	*next;

	prev = head->prev;
	next = head->next;
	if (head->next == prev)
		return (rotate_list(head));
	prev->next = next;
	head->prev = next;
	head->next = next->next;
	next->prev = prev;
	next->next->prev = head;
	next->next = head;
	return (next);
}

t_list	*swap_down(t_list *head)
{
	if (head->next == head->prev)
		return (rotate_list(head));
	head = reverse_rotate_list(reverse_rotate_list(head));
	head = swap_top(head);
	head = rotate_list(rotate_list(head));
	return (head);
}

char	**list_to_arrchar(t_list *env)
{
	char	**res;
	t_list	*head;

	res = malloc(sizeof(char *) * (list_size(env) + 1));
	head = env;
	while (head->next != env)
	{
		*res = ft_strjoin(head->key, "=");
		*res = ft_strjoin(*res, head->val);
		head = head->next;
		(*res)++;
	}
	*res = NULL;
	return (res);
}
