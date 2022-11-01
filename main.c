/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:13:40 by rdeanne           #+#    #+#             */
/*   Updated: 2022/11/01 10:05:14 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		g_sigint;

int	in_builtins(char *cmd)
{
	return (!ft_strcmp(cmd, "cd") || !ft_strcmp(cmd, "echo")
		|| !ft_strcmp(cmd, "env") || !ft_strcmp(cmd, "exit")
		|| !ft_strcmp(cmd, "export") || !ft_strcmp(cmd, "pwd")
		|| !ft_strcmp(cmd, "unset"));
}

static void	handler(int signo, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signo == SIGINT)
	{
		write(STDOUT, "\n", 1);
		write(STDOUT, PROMT, ft_strlen(PROMT));
		g_sigint = 1;
	}
}

void	termios_setup(struct termios *term)
{
	term->c_iflag = BRKINT | ICRNL | IXON
		| IXANY | IMAXBEL | IUTF8;
	term->c_cflag = CSIZE | CREAD | HUPCL;
	term->c_lflag = ISIG | ICANON | ECHO
		| ECHOE | ECHOK | ECHOKE;
	term->c_oflag = OPOST | ONLCR;
	term->c_cc[VQUIT] = 0;
}

int	main(int argc, char **argv, char **envp)
{
	char				*line;
	char				**splited_line;
	t_shell				*shell;
	struct sigaction	sa;
	struct termios		term, original;

	(void)argc;
	(void)argv;
	(void)envp;
	g_sigint = 0;
	if (tcgetattr(fileno(stdin), &term) < 0)
	{
		perror("Error getting terminal information");
		return (-1);
	}
	original = term;
	termios_setup(&term);
	if (tcsetattr(fileno(stdin), TCSANOW, &term) < 0)
	{
		perror("Error setting terminal information");
		return (-1);
	}
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigaction(SIGINT, &sa, NULL);
	shell = malloc(sizeof(t_shell));
	init_shell(shell);
	init_env(shell, envp);
	while (!shell->exit_flag)
	{
		line = readline(PROMT);
		if (!line)
		{
			printf("\x1B[u\x1B[Aexit\n");
			free_shell(shell);
			rl_clear_history();
			if (tcsetattr(fileno(stdin), TCSANOW, &original) < 0)
			{
				perror("Error setting terminal information");
				rl_clear_history();
				return (-1);
			}
			return (0);
		}
		if (g_sigint == 0)
		{
			add_history(line);
			splited_line = ft_split(line, ' ');
			if (splited_line[0])
			{
				if (!in_builtins(splited_line[0]))
					shell->exit_status = exec_cmd(splited_line, envp, shell);
				else
					shell->exit_status = exec_builtin(splited_line, shell);
			}
		}
		if (line)
			free(line);
		g_sigint = 0;
	}
	if (tcsetattr(fileno(stdin), TCSANOW, &original) < 0)
	{
		perror("Error setting terminal information");
		rl_clear_history();
		return (-1);
	}
	rl_clear_history();
	return (0);
}
