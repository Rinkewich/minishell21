/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spliter.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:33:09 by fardath           #+#    #+#             */
/*   Updated: 2022/11/07 15:01:02 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLITER_H
# define SPLITER_H

typedef struct s_split_data
{
	char	*line;
	int		index;
	char	**words;
}	t_split_data;

# define QUOTES_D	'"'
# define QUOTES_S	'\''
# define SPACE		' '

# define HEREDOC	"<<"
# define REDIRIN	"<"
# define REDIROUT	">"
# define REDIROUT_A ">>"
# define PIPE		"|"

void	spliter(t_plit *split);
char	check_letter(t_split_data *data);
int		check_separator(t_split_data *data);
void	put_separator(t_split_data *data);
int		check_quote(t_split_data *data);
void	put_quote(t_split_data *data);
void	put_word(t_split_data *data);

#endif