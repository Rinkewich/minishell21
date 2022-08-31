NAME	=	minishell
CC		=	gcc
CFLAGS	=	-Werror -Wall -Wextra
INCLUDE	=	-I includes

LIBFTNAME	=	libft.a

OBJDIR	=	obj
SRCDIR	=	src
BUILTINS	=	src/builtins
GNL		=	gnl
HEADERS	=	includes/minishell.h includes/libft.h includes/get_next_line.h

LIBFTPATH	=	libft

SRC		=	main.c		utils.c		init.c			list_operations_1.c		list_operations_2.c	list_operations_3.c \
			echo.c		pwd.c		cd.c			env.c					unset.c				export.c			\
			exit.c		execve.c	get_next_line.c	get_next_line_utils.c	

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

$(OBJDIR)/%.o	:	$(BUILTINS)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR)/%.o	:	$(GNL)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean	:
	make -C ${LIBFTPATH} clean
	rm -d -f -r $(OBJDIR)

fclean	:	clean
	make -C ${LIBFTPATH} fclean
	rm -f $(NAME)

re		: fclean all
