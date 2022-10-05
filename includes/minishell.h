/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:57:47 by rdeanne           #+#    #+#             */
/*   Updated: 2022/10/05 14:08:27 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <errno.h>

# include "libft.h"

# define PROMT "minishell: \x1B[s"
# define MAX_PATH 1024

// Tokens types
# define EMPTY 0
# define CMD 1
# define ARG 2
# define REDIR_INPUT 3	// <
# define REDIR_OUTPUT 4	// >
# define REDIR_APPEND 5	// >>
# define HEREDOC 6		// <<
# define PIPE 9			// |

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_list
{
	char			*key;
	char			*val;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_token
{
	char			*val;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

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
int		list_size(t_list *a);
t_list	*sort_list(t_list *list);
void	delete_list(t_list **head);
t_list	*copy_list(t_list *src);
t_list	*get_list(t_list *head, char *key);

// builtins
int		ft_cd(const char *path);
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
void	init_env(t_shell *shell, char **envp);

// utils
void	print_list(t_list *head);
void	print_export_list(t_list *head);
void	ptr_swap(char **p1, char **p2);

extern int	g_sigint;

#endif