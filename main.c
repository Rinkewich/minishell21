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

	// printf("0: %d\n", term.c_cc[0]);
	// printf("1: %d\n", term.c_cc[1]);
	// printf("2: %d\n", term.c_cc[2]);
	// printf("3: %d\n", term.c_cc[3]);
	// printf("4: %d\n", term.c_cc[4]);
	// printf("5: %d\n", term.c_cc[5]);
	// printf("6: %d\n", term.c_cc[6]);
	// printf("7: %d\n", term.c_cc[7]);
	// printf("8: %d\n", term.c_cc[9]);
	// printf("9: %d\n", term.c_cc[8]);
	// printf("10: %d\n", term.c_cc[10]);
	// printf("11: %d\n", term.c_cc[11]);
	// printf("12: %d\n", term.c_cc[12]);
	// printf("13: %d\n", term.c_cc[13]);
	// printf("14: %d\n", term.c_cc[14]);
	// printf("15: %d\n", term.c_cc[15]);
	// printf("16: %d\n", term.c_cc[16]);
	// printf("17: %d\n", term.c_cc[17]);
	// printf("18: %d\n", term.c_cc[18]);
	// printf("19: %d\n", term.c_cc[19]);
	// printf("20: %d\n", term.c_cc[20]);

	
	// 	  ECHOKE      /* visual erase for line kill */
	//    ECHOE       /* visually erase chars */
	//    ECHO        /* enable echoing */
	//    ECHONL      /* echo NL even if ECHO is off */
	//    ECHOPRT     /* visual erase mode for hardcopy */
	//    ECHOCTL     /* echo control chars as ^(Char) */
	//    ISIG        /* enable signals INTR, QUIT, [D]SUSP */
	//    ICANON      /* canonicalize input lines */
	//    ALTWERASE   /* use alternate WERASE algorithm */
	//    IEXTEN      /* enable DISCARD and LNEXT */
	//    EXTPROC     /* external processing */
	//    TOSTOP      /* stop background jobs from output */
	//    FLUSHO      /* output being flushed (state) */
	//    NOKERNINFO  /* no kernel output from VSTATUS */
	//    PENDIN      /* XXX retype pending input (state) */
	//    NOFLSH      /* don't flush after interrupt */
	

#include "minishell.h"
#include "get_next_line.h"

t_sig g_sig;

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
		write(1, "\b\b  \n", 5);
		g_sig.sigint = 1;
	}
	else if (signo == SIGQUIT)
	{
		write(1, "\b\b  \b\b", 6);
		g_sig.sigquit = 1;
	}
}

void termios_setup(struct termios *term)
{
	term->c_iflag = 
					BRKINT |
					ICRNL |
					IXON |
					IXANY |
					IMAXBEL |
					IUTF8;
					// IGNBRK |
					// IGNPAR |
					// PARMRK |
					// INPCK |
					// ISTRIP |
					// INLCR |
					// IGNCR |
					// IXOFF;
	// 27394
	// 28671
	term->c_cflag = CSIZE |
					CREAD |
					HUPCL;
					// CSTOPB |
					// PARENB |
					// PARODD;
					// CLOCAL;
	// 19200
	// 65280
	// printf("%ld\n%ld\n", term->c_iflag, term->c_cflag);
	term->c_lflag = ISIG |
					ICANON |
					ECHO |
					ECHOE |
					ECHOCTL |
					
					ECHOK |
					ECHOKE |
					// PENDIN |
					// IEXTEN |
					// ALTWERASE |
					// NOKERNINFO |
					// EXTPROC |
					// ECHONL|
					// TOSTOP |
					// FLUSHO |
					// ECHOPRT |
					NOFLSH;
	term->c_oflag = OPOST | ONLCR;
	// term->c_ispeed = 38400;
	// term->c_ospeed = 38400;

	term->c_cc[VEOF] = 4;
	term->c_cc[VEOL] = 255;
	term->c_cc[VEOL2] = 255;
	term->c_cc[VERASE] = 127;
	term->c_cc[4] = 23;
	term->c_cc[VKILL] = 21;
	term->c_cc[6] = 18;
	term->c_cc[7] = 0;
	term->c_cc[VINTR] = 3;
	term->c_cc[VQUIT] = 28;
	term->c_cc[VSUSP] = 26;
	term->c_cc[11] = 25;
	term->c_cc[VSTART] = 17;
	term->c_cc[VSTOP] = 19;
	term->c_cc[14] = 22;
	term->c_cc[15] = 15;
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	term->c_cc[18] = 20;
	term->c_cc[19] = 0;
	term->c_cc[20] = 0;
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
	
	if (tcgetattr(fileno(stdin), &term) < 0) {
		perror("Error getting terminal information");
		return -1;
	}
	original = term;
	// termios_setup(&term);	
	// if (tcsetattr(fileno(stdin), TCSANOW, &term) < 0) {
	// 	perror("Error setting terminal information");
	// 	return -1;
	// }
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
	shell = malloc(sizeof(t_shell));
	init_shell(shell);
	init_env(shell, envp);
	while (!shell->exit_flag)
	{
		if (!g_sig.sigquit)
			write(1, "minishell : ", 12);
		g_sig.sigint = 0;
		g_sig.sigquit = 0;
		line = get_next_line(0);
		if (!line && !g_sig.sigint && !g_sig.sigquit)
		{
			printf("exit\n");
			free_shell(shell);
			if (tcsetattr(fileno(stdin), TCSANOW, &original) < 0) {
				perror("Error setting terminal information");
				return -1;
			}
			return (0);
		}
		add_history(line);
		splited_line = ft_split(line, ' ');
		if (splited_line[0])
		{
			if (!in_builtins(splited_line[0]))
				exec_cmd(splited_line, envp, shell);
			else
				exec_builtin(splited_line, shell);
		}
		if (line)
			free(line);
	}
	if (tcsetattr(fileno(stdin), TCSANOW, &original) < 0) {
		perror("Error setting terminal information");
		return -1;
	}
	return (0);
}
