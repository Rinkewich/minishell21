/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:13:40 by rdeanne           #+#    #+#             */
/*   Updated: 2022/06/17 12:31:35 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "get_next_line.h"

int gsigint;

int	in_builtins(char *cmd)
{
	return (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "env") ||
			!ft_strcmp(cmd, "exit") || !ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "pwd") ||
			!ft_strcmp(cmd, "unset"));
}

static void	handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signo == SIGINT)
	{
		printf("\b\b  ");
		printf("\n");
		gsigint = 1;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char				*line;
	char				**splited_line;
	t_shell				*shell;
	struct sigaction	sa;

	(void)argc;
	(void)argv;
	(void)envp;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigaction(SIGINT, &sa, NULL);

	shell = malloc(sizeof(t_shell));
	init_shell(shell);
	init_env(shell, envp);
	while (!shell->exit_flag)
	{
		line = get_next_line(0);
		if (!line && !gsigint)
		{
			printf("exit\n");
			free_shell(shell);
			return (0);
		}
		gsigint = 0;
		add_history(line);
		splited_line = ft_split(line, ' ');
		if (splited_line[0])
		{
			if (!in_builtins(splited_line[0]))
				exec_cmd(splited_line, envp, shell);
			else
				exec_builtin(splited_line, shell);
		}
		// ft_env(shell);
		// ft_export(shell, "aaa=1");
		// ft_export(shell, "aaaaaa=2");
		// ft_unset(shell, "aaa");
		// ft_export(shell, "a=3");
		// ft_export(shell, "");
		// printf("\n");
		// ft_env(shell);
		// printf("\n");
		// ft_echo("hello world!", 0);
		// ft_export(shell, "b=2");
		// ft_export(shell, "c=3");
		// ft_env(shell);
		// ft_export(shell, "");
		// ft_unset(shell, "asd");
		// parse_line(line, shell);
		free(line);
	}
	return (0);
}
