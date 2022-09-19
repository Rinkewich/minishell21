/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:53:07 by rdeanne           #+#    #+#             */
/*   Updated: 2022/09/19 14:44:07 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

int		newline_check(char *str, int rd)
{
	if (rd == 0 && str[0] == '\0')
		return (2);
	if (rd == 0 || str == NULL)
		return (0);
	if (ft_strchr(str, '\n'))
		return (1);
	return (0);
}

char	*read_to_endl(int fd, char *str)
{
	char	buf[BUFFER_SIZE + 1];
	int		rd;

	rd = 1;
	while (!newline_check(str, rd))
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
			return (NULL);
		buf[rd] = '\0';
		// if (rd == 0 || buf[rd - 1] != '\n')
		// {
		// 	write(1, "  \b\b", 4);
		// 	// write(1, buf, ft_strlen(buf));
		// 	// write(1, "\n", 1);
		// }
		str = ft_strjoin(str, buf);
	}
	return (str);
}

char	*update_prev(char *str)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!res)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}

char	*get_line(char	*str)
{
	size_t	i;
	char	*res;

	i = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	// if (str[i] == '\n')
	// {
	// 	res[i] = str[i];
	// 	i++;
	// }
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*prev;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	prev = read_to_endl(fd, prev);
	if (!prev)
		return (NULL);
	res = get_line(prev);
	prev = update_prev(prev);
	return (res);
}
