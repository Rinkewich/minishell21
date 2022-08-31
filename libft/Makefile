NAME	=	libft.a
CC		=	gcc

HEADER	=	../includes/libft.h
INCLUDE	=	../includes
OBJDIR	=	obj

CFLAGS	=	-Wall -Wextra -Werror -I $(INCLUDE)

SRCS	=	ft_atoi.c		ft_isdigit.c	ft_inset.c 		ft_isspace.c 	ft_putnbr_fd.c	ft_split.c\
			ft_strchr.c		ft_strjoin.c	ft_strlen.c 	ft_isnum.c		ft_putendl_fd.c	ft_chrpos.c\
			ft_strrchr.c	ft_tolower.c	ft_tolower.c	ft_strncmp.c	ft_putstr_fd.c 	ft_strndup.c\
			

OBJS	=	$(SRCS:%.c=$(OBJDIR)/%.o)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(OBJDIR)	:
	mkdir $(OBJDIR)

$(NAME)	:	$(OBJDIR) $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)

$(OBJDIR)/%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -d -f -r $(OBJDIR)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all