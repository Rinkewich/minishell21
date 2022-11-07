/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:03:45 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 19:43:46 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_heredoc(char *word)
{
	if (ft_strlen(word) == ft_strlen(HEREDOC)
		&& ft_strncmp(word, HEREDOC, ft_strlen(HEREDOC)) == 0)
		return (1);
	return (0);
}

int	find_redirout(char *word)
{
	if (ft_strlen(word) == ft_strlen(REDIROUT)
		&& ft_strncmp(word, REDIROUT, ft_strlen(REDIROUT)) == 0)
		return (1);
	return (0);
}

int	find_redirin(char *word)
{
	if (ft_strlen(word) == ft_strlen(REDIRIN)
		&& ft_strncmp(word, REDIRIN, ft_strlen(REDIRIN)) == 0)
		return (1);
	return (0);
}

int	find_redirout_a(char *word)
{
	if (ft_strlen(word) == ft_strlen(REDIROUT_A)
		&& ft_strncmp(word, REDIROUT_A, ft_strlen(REDIROUT_A)) == 0)
		return (1);
	return (0);
}

int	find_redirect(t_parser *data)
{
	char	*word;

	word = check_word(data);
	if (find_heredoc(word)
		|| find_redirout(word)
		|| find_redirin(word)
		|| find_redirout_a(word))
		return (1);
	return (0);
}
