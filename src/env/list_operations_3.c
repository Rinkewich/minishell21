/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_operations_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:45:27 by rdeanne           #+#    #+#             */
/*   Updated: 2022/11/07 15:30:18 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*sort_list(t_list *head)
{
	t_list	*cur;
	t_list	*index;

	cur = head;
	while (cur->next != head)
	{
		index = cur->next;
		if (ft_strncmp(cur->key, index->key, ft_strlen(cur->key)) > 0)
		{
			ptr_swap(&cur->key, &index->key);
			ptr_swap(&cur->val, &index->val);
		}
		index = index->next;
		while (index != head)
		{
			if (ft_strncmp(cur->key, index->key, ft_strlen(cur->key)) > 0)
			{
				ptr_swap(&cur->key, &index->key);
				ptr_swap(&cur->val, &index->val);
			}
			index = index->next;
		}
		cur = cur->next;
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
	t_list	*cur;
	char	*key;
	char	*val;

	key = ft_strndup(src->key, ft_strlen(src->key));
	val = ft_strndup(src->val, ft_strlen(src->val));
	dst = create_list(key, val);
	cur = src->next;
	while (cur != src)
	{
		key = ft_strndup(cur->key, ft_strlen(cur->key));
		val = ft_strndup(cur->val, ft_strlen(cur->val));
		dst = push_list(dst, key, val);
		cur = cur->next;
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

int	list_size(t_list *a)
{
	t_list	*head;
	int		i;

	i = 1;
	head = a;
	while (head->next != a)
	{
		head = head->next;
		i++;
	}	
	return (i);
}
