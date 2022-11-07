/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:36:26 by fardath           #+#    #+#             */
/*   Updated: 2022/11/07 17:54:42 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# define PROMT "\033[7m\033[35mminishell$:\033[0m \x1B[s"
// # define PROMT "minishell-2.1$ \x1B[s"

# define SEPARATORS " 	<>|$\"\'"

typedef enum e_type
{
	Heredoc,
	Redirin,
	Redirout,
	Redirout_a,
	Pipe,
	Command
}	t_type;

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
	t_type			type;
	char			**argv;
	struct s_token	*next;
}	t_token;

typedef struct s_plit
{
	int		argc;
	int		temporary;
	char	**argv;
	t_list	*env;
	char	*line;
	char	**split_line;
	int		pid;
	t_token	**tokens;
}	t_plit;

void	what_env(t_plit *split, int sq, int dq, int i);

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
int		list_size(t_list *a);
char	**list_to_arrchar(t_list *env);
void	print_list(t_list *head);
void	print_export_list(t_list *head);
void	ptr_swap(char **p1, char **p2);

#endif