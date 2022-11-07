/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:20:28 by fardath           #+#    #+#             */
/*   Updated: 2022/11/07 15:12:15 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "minishell.h"

typedef struct s_command
{
	char	*name;
	char	**argv;
	int		*fdin;
	int		*fdout;
}	t_command;

typedef struct s_executer_utils
{
	int		pin;
	int		pout;
	t_token	*current_fast;
	t_token	*current_slow;
}	t_executer_utils;

void		execute_bins(t_plit *mini);
t_command	*new_command(char *name, char **argv, int pin, int pout);
char		*find_path(t_plit *mini, char *name);

void		fill_executor_struct(t_executer_utils *utils, t_plit *mini);

void		duplicate_fdout(int *fdout);
void		duplicate_fdin(int *fdin);
void		close_fds(t_command *cmd);
void		close_pipe(int pin, int pout);

int			*arrint_new(int len);
int			arrint_len(int *arr);
int			*arrint_addback(int *old_arr, int new_elem);
int			is_builtin(char	*name);

void		execute_builtin(t_plit *mini, t_command *cmd);
void		execute_command(t_plit *mini, t_command *cmd);
void		post_execution(t_plit *mini);

void		open_redir(t_token	*current, t_command *cmd);
void		open_heredoc(char *filename, t_command *cmd);
void		open_redirin(char *filename, t_command *cmd);
void		open_redirout(char *filename, t_command *cmd);
void		open_redirout_a(char *filename, t_command *cmd);

#endif