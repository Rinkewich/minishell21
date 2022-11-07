/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:57:47 by rdeanne           #+#    #+#             */
/*   Updated: 2022/11/07 11:44:50 by rdeanne          ###   ########.fr       */
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

# define PROMT "minishell-2.1$ \x1B[s"
# define MAX_PATH 1024

# define STDIN 0
# define STDOUT 1
# define STDERR 2

extern int	g_sigint;

typedef struct s_list
{
	char			*key;
	char			*val;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_shell
{
	int		fdin;
	int		fdout;
	t_list	*env_list;
	int		exit_flag;
	int		exit_status;
}	t_shell;

void	init_shell(t_shell *shell);
void	free_shell(t_shell *shell);

// redirection
void	redir_output(t_shell *shell, t_token *token, int type);
void	redir_input(t_shell *shell, t_token *token);
void	reset_std(t_shell *shell);

// tokens list
t_token	*create_token(char *val, int type);
t_token	*push_token(t_token *head, char *val, int type);
void	delete_tokens(t_token **head);

// list operations:
t_list	*create_list(char *key, char *val);
t_list	*push_list(t_list *head, char *key, char *val);
t_list	*pop_list(t_list *head);
t_list	*update_list(t_list *head, char *key, char *val);
t_list	*delete_env(t_list *head, char *key);
t_list	*rotate_list(t_list *head);
t_list	*reverse_rotate_list(t_list *head);
t_list	*swap_top(t_list *head);
t_list	*swap_down(t_list *head);
t_list	*sort_list(t_list *list);
void	delete_list(t_list **head);
t_list	*copy_list(t_list *src);
t_list	*get_list(t_list *head, char *key);

// builtins
int		ft_cd(const char *path, t_list *envp);
int		ft_echo(char **argv);
int		ft_pwd(void);
int		ft_exit(t_shell *shell);
int		ft_export(t_shell *shell, char *str);
int		ft_unset(t_shell *shell, char *key);
int		ft_env(t_shell *shell);

// execve
int		exec_cmd(char **argv, char **envp, t_shell *shell);
int		exec_builtin(char **argv, t_shell *shell);

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