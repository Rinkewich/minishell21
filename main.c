/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:26:58 by fardath           #+#    #+#             */
/*   Updated: 2022/11/07 10:41:13 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_sigint;

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

void	master(t_plit *split)
{
	while (1)
	{
		g_sigint = 0;
		split->line = readline(PROMT);
		if (!split->line)
		{
			g_sigint = 128 - 1;
			printf("\x1B[u\x1B[Aexit\n");
			exit(g_sigint);
		}
		if (ft_strlen(split->line) == 0 && split->line[0] == 0)
			;
		else if (g_sigint != 1)
		{
			add_history(split->line);
			what_env(split, 0, 0, 0);
			spliter(split);
			parser(split);
			execute(split);
		}
		free(split->line);
	}
}

int	setup_terminal_settings(struct termios *term)
{
	struct termios	original;

	if (tcgetattr(fileno(stdin), term) < 0)
	{
		perror("Error getting terminal information");
		return (-1);
	}
	original = *term;
	termios_setup(term);
	if (tcsetattr(fileno(stdin), TCSANOW, term) < 0)
	{
		perror("Error setting terminal information");
		return (-1);
	}
	*term = original;
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_plit				*split;
	struct sigaction	sa;
	struct termios		term;

	g_sigint = 0;
	if (setup_terminal_settings(&term) == -1)
		return (-1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigaction(SIGINT, &sa, NULL);
	split = init_plit(argc, argv, envp);
	master(split);
	if (tcsetattr(fileno(stdin), TCSANOW, &term) < 0)
	{
		perror("Error setting terminal information");
		return (-1);
	}
	return (0);
}
