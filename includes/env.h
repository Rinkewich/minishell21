/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:36:26 by fardath           #+#    #+#             */
/*   Updated: 2022/11/07 12:09:05 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

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

t_plit	*init_plit(int argc, char **argv, char **env);
char	**init_env_lvl(char **env);
char	*env_find_val(char *val, t_list *env);
char	**export_var(char *arg, char **env);
char	*ft_strcpy_len(char *src, int len);
char	**add_var(char **env, char *arg);
char	**unset_var(char *var, char **env);
void	free_env(char **env);
char	**delete_var(char **env, int pos);
void	what_env(t_plit *split, int sq, int dq, int i);
#endif