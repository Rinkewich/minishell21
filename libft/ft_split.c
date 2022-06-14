/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:45:08 by rdeanne           #+#    #+#             */
/*   Updated: 2022/03/08 11:10:27 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	get_del_num(const char *s, char c)
{
	size_t	i;
	size_t	size;

	size = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 && s[0] != c) || \
			(s[i] == c && s[i + 1] != c && s[i + 1] != '\0'))
			size++;
		i++;
	}
	return (size + 1);
}

static char	*get_substr(const char *s, char c, size_t *i)
{
	char	*res;
	size_t	k;
	size_t	j;

	while (s[*i] == c)
		(*i)++;
	k = 0;
	while (s[*i] != c && s[*i])
	{
		k++;
		(*i)++;
	}
	res = malloc(sizeof(char) *(k + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (j < k + 1)
	{
		res[j] = s[*i - k + j];
		j++;
	}
	res[k] = '\0';
	return (res);
}

static void	free_arrstr(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static int	putstr_tosplit(char **res, const char *s, size_t size, char c)
{
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	while (s[i] && k < size - 1)
	{
		if (i == 0 || (s[i] == c && s[i + 1] != c))
		{
			res[k] = get_substr(s, c, &i);
			if (!res[k++])
				return (0);
			i--;
		}
		i++;
	}
	res[size - 1] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	size;

	if (!s || s[0] == '\0')
	{
		res = malloc(sizeof(char *) * 1);
		if (!res)
			return (NULL);
		res[0] = NULL;
		return (res);
	}
	size = get_del_num(s, c);
	res = malloc(sizeof(char *) * size);
	if (!res)
		return (NULL);
	if (!putstr_tosplit(res, s, size, c))
	{
		free_arrstr(res);
		return (NULL);
	}
	return (res);
}
