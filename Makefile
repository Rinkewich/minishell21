# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fardath <fardath@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 17:03:28 by fardath           #+#    #+#              #
#    Updated: 2022/11/06 17:03:50 by fardath          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE	=	-I includes

LIBFTNAME	=	libft.a

OBJDIR	=	obj
SRCDIR	=	src
BUILTINS	=	src/builtins
ENV		=	src/env
INIT	=	src/init
SPLITER		= src/spliter
PARSER		= src/parser
EXECUTOR	= src/executor
BUILTINS	= src/builtins

HEADERS	=	includes/minishell.h includes/libft.h	includes/env.h\
			includes/spliter.h	includes/parser.h	includes/executor.h  

LIBFTPATH	=	libft

SRC		=	main.c			env_find_val.c	init_plite.c\
			init_shlvl.c\
			what_env.c		spliter.c		check_letter.c\
			check_separator.c	check_quote.c	check_word.c\
			parser.c		init_parser.c		parser_utils.c\
			find_redirect.c	put_redirect.c		token.c\
			find_pipe.c		put_pipe.c			put_command.c\
			\
			executor.c	command.c			open_redir.c\
			findpath.c	duplicate_fd.c		post_execution.c\
			execute_bin.c	execute_builtin.c executor_utils.c\
			executor_bins.c\
			\
			builtins.c	mini_echo.c	mini_cd_utils.c\
			mini_cd.c	mini_env.c	mini_pwd.c\
			mini_exit.c	mini_unset.c	mini_export.c\
			print_errormsg.c\

OBJ		=	$(SRC:%.c=$(OBJDIR)/%.o)

.PHONY	:	all clean fclean re

all			:	$(NAME)
	@make -C ${LIBFTPATH}

$(OBJDIR)	:
	mkdir $(OBJDIR)

$(NAME)		:	$(OBJDIR) $(OBJ)
	make -C ${LIBFTPATH}
	$(CC) $(CFLAGS) -lreadline $(OBJ) ${LIBFTPATH}/${LIBFTNAME} -o $(NAME)

$(OBJDIR)/%.o	:	%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)/%.o	:	$(ENV)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)/%.o	:	$(INIT)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)/%.o	:	$(SPLITER)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)/%.o	:	$(PARSER)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)/%.o	:	$(EXECUTOR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)/%.o	:	$(BUILTINS)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean	:
	make -C ${LIBFTPATH} clean
	rm -d -f -r $(OBJDIR)

fclean	:	clean
	make -C ${LIBFTPATH} fclean
	rm -f $(NAME)

re		: fclean all
