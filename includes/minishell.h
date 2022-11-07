/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:57:47 by rdeanne           #+#    #+#             */
/*   Updated: 2022/11/07 17:57:37 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <string.h>
# include <signal.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <termios.h>
# include "libft.h"
# include "env.h"
# include "spliter.h"
# include "parser.h"
# include "executor.h"

# define MAX_PATH 1024

# define STDIN 0
# define STDOUT 1
# define STDERR 2

extern int	g_sigint;

t_plit	*init_plit(int argc, char **argv, char **env);

// builtins
int		ft_cd(char *path, t_list *envp);
void	ft_echo(t_command *cmd);
int		ft_pwd(void);
void	ft_exit(t_command *cmd);
int		ft_export(t_plit *shell, char **argv);
int		ft_unset(t_plit *shell, char **argv);
int		ft_env(t_plit *shell);

// env
char	**parse_env_str(char *str);

// utils
void	print_list(t_list *head);
void	print_export_list(t_list *head);
void	ptr_swap(char **p1, char **p2);

void	print_errormsg(char *errormsg);
void	mini_pwd(void);
void	clear_tokens(t_token *token);
void	clear_heredoc(t_token *token);
void	execute(t_plit *mini);

#endif