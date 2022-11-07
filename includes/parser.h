/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:24:01 by fardath           #+#    #+#             */
/*   Updated: 2022/11/06 19:50:48 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_parser
{
	char			**words;
	int				command_is_set;
	int				index;
	t_token			*current_command;
	t_token			**head;
}	t_parser;

void		parser(t_plit *split);
t_parser	*init_parser(char **split);
char		*check_word(t_parser *data);
int			find_redirect(t_parser *data);
int			find_heredoc(char *word);
int			find_redirout(char *word);
int			find_redirin(char *word);
int			find_redirout_a(char *word);
void		put_redirect(t_plit *split, t_parser *data);
t_token		*new_token(char *name, t_type type);
void		token_push_back(t_token **head, t_token *to_push);
int			find_pipe(t_parser *data);
void		put_pipe(t_parser *data);
int			command_set(t_parser *data);
void		add_to_argv(t_parser *data);
char		*remove_quotes(char *word);
void		put_command(t_parser *data);
void		clear_token(t_token *token);

#endif
