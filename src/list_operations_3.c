/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:45:27 by rdeanne           #+#    #+#             */
/*   Updated: 2022/06/14 13:01:47 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_list	*sort_list(t_list *head)
{
	t_list	*current;
	t_list	*index;

	current = head;
	while (current->next != head)
	{
		index = current->next;
		if (ft_strncmp(current->key, index->key, ft_strlen(current->key)) > 0)
		{
			ptr_swap(&current->key, &index->key);
			ptr_swap(&current->val, &index->val);
		}
		index = index->next;
		while (index != head)
		{
			if (ft_strncmp(current->key, index->key, ft_strlen(current->key)) > 0)
			{
				ptr_swap(&current->key, &index->key);
				ptr_swap(&current->val, &index->val);
			}
			index = index->next;
		}
		current = current->next;
	}
	return (head);
}

t_list	*delete_env(t_list *head, char *key)
{
	t_list	*begin;

	begin = head;
	if (!head)
		return (NULL);
	if (!ft_strcmp(head->key, key))
		return (pop_list(head));
	head = head->next;
	while (head != begin)
	{
		if (!ft_strcmp(head->key, key))
		{
			pop_list(head);
			return (begin);
		}	
		head = head->next;
	}
	return (begin);
}

t_list	*copy_list(t_list *src)
{
	t_list	*dst;
	t_list	*current;
	char	*key;
	char	*val;

	key = ft_strndup(src->key, ft_strlen(src->key));
	val = ft_strndup(src->val, ft_strlen(src->val));
	dst = create_list(key, val);
	current = src->next;
	while (current != src)
	{
		key = ft_strndup(current->key, ft_strlen(current->key));
		val = ft_strndup(current->val, ft_strlen(current->val));
		dst = push_list(dst, key, val);
		current = current->next;
	}
	return (dst);
}

t_list	*get_list(t_list *head, char *key)
{
	t_list	*tmp_list;

	tmp_list = head;
	if (ft_strcmp(tmp_list->key, key) == 0)
		return (tmp_list);
	tmp_list = tmp_list->next;
	while (tmp_list != head)
	{
		if (ft_strcmp(tmp_list->key, key) == 0)
			return (tmp_list);
		tmp_list = tmp_list->next;
	}
	return (NULL);
}
