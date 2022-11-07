/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdeanne <rdeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:55:52 by fardath           #+#    #+#             */
/*   Updated: 2022/11/07 16:54:57 by rdeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*proc_herdoc(char *stopword)
{
	char	*tmp;
	char	*result;
	char	*line;

	result = ft_strnew(0);
	line = ft_strnew(0);
	line = readline("> ");
	while (ft_strlen(line) != ft_strlen(stopword)
		|| ft_strncmp(line, stopword, ft_strlen(stopword)))
	{
		tmp = result;
		result = ft_strjoin(result, line);
		free(tmp);
		tmp = result;
		result = ft_strjoin(result, "\n");
		free(tmp);
		line = readline("> ");
	}
	return (result);
}

char	*heredoc_file(t_plit *split)
{
	char	*tmp;
	char	*result;
	char	*pid;
	char	*id;

	result = "/tmp/heredoc_";
	pid = ft_itoa(split->pid);
	result = ft_strjoin(result, pid);
	free(pid);
	tmp = result;
	result = ft_strjoin(result, "_");
	free(tmp);
	id = ft_itoa(split->temporary++);
	tmp = result;
	result = ft_strjoin(result, id);
	free(id);
	free(tmp);
	return (result);
}

char	*put_heredoc(t_plit *split, t_parser *data)
{
	int		fd;
	char	*fd_str;
	char	*filename;
	char	*result;
	char	*stopword;

	data->index++;
	stopword = check_word(data);
	result = proc_herdoc(stopword);
	filename = heredoc_file(split);
	fd = open(filename, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(filename);
		exit(0);
	}
	if (write(fd, result, ft_strlen(result)) == -1)
	{
		fd_str = ft_itoa(fd);
		perror(fd_str);
		free(fd_str);
		exit(0);
	}
	close(fd);
	return (filename);
}

void	put_redirect(t_plit *split, t_parser *data)
{
	t_token	*reder_token;
	char	*filename;
	char	*redirtype;

	redirtype = check_word(data);
	filename = NULL;
	if (find_heredoc(redirtype))
	{
		filename = put_heredoc(split, data);
		reder_token = new_token(redirtype, Heredoc);
	}
	else if (find_redirin(redirtype))
		reder_token = new_token(redirtype, Redirin);
	else if (find_redirout(redirtype))
		reder_token = new_token(redirtype, Redirout);
	else
		reder_token = new_token(redirtype, Redirout_a);
	if (find_heredoc(redirtype) == 0)
	{
		data->index++;
		filename = check_word(data);
	}
	reder_token->argv = ft_arr_addback(reder_token->argv, filename);
	token_push_back(data->head, reder_token);
	data->index++;
}
