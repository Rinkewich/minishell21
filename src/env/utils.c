/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:11:41 by rdeanne           #+#    #+#             */
/*   Updated: 2022/11/07 15:55:24 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_list(t_list *head)
{
	t_list	*tmp_list;

	if (!head)
		return ;
	tmp_list = head;
	printf("%s=%s\n", tmp_list->key, tmp_list->val);
	tmp_list = tmp_list->next;
	while (tmp_list != head)
	{
		printf("%s=%s\n", tmp_list->key, tmp_list->val);
		tmp_list = tmp_list->next;
	}
}

void	print_export_list(t_list *head)
{
	t_list	*tmp_list;

	if (!head)
		return ;
	tmp_list = head;
	printf("declare -x %s=%s\n", tmp_list->key, tmp_list->val);
	tmp_list = tmp_list->next;
	while (tmp_list != head)
	{
		printf("declare -x %s=%s\n", tmp_list->key, tmp_list->val);
		tmp_list = tmp_list->next;
	}
}

void	ptr_swap(char **p1, char **p2)
{
	char	*tmp;

	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
