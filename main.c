/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:13:40 by rdeanne           #+#    #+#             */
/*   Updated: 2022/06/14 14:24:12 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	// char				*line;
	// char				**splited_line;
	t_shell				*shell;

	(void)argc;
	(void)argv;
	(void)envp;
	shell = malloc(sizeof(t_shell));
	init_shell(shell);
	init_env(shell, envp);
	// while (!shell->exit_flag)
	// {
	// 	line = readline(PROMT);
	// 	if (!line)
	// 	{
	// 		printf("exit\n");
	// 		free_shell(shell);
	// 		return (0);
	// 	}
	// 	add_history(line);
	// 	splited_line = ft_split(line, ' ');
	// 	if (splited_line[0])
	// 		exec_cmd(splited_line[0], splited_line, envp, shell);

		ft_env(shell);
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
		// free(line);
	// }
	return (0);
}