# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jucollet <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 21:26:15 by jucollet     #+#   ##    ##    #+#        #
#    Updated: 2018/12/12 21:19:43 by jucollet    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME=libft.a

CC=gcc

CFLAGS= -Wall -Werror -Wextra -c

INCLUDES= libft.h

SRCO =  $(SRC:.c=.o)

SRC =	ft_isalpha.c						ft_isdigit.c					ft_lstaddback.c\
		ft_isalnum.c						ft_isascii.c					ft_lstmap.c\
		ft_isprint.c						ft_toupper.c					ft_lstiter.c\
		ft_tolower.c						ft_atoi.c						ft_lstdelone.c\
		ft_strcmp.c							ft_strncmp.c					ft_lstadd.c\
		ft_strcat.c							ft_strncat.c					ft_lstnew.c\
		ft_strlen.c							ft_strdup.c						ft_lstiter.c\
		ft_isspace.c						ft_bzero.c						ft_lstdel.c\
		ft_memset.c							ft_memcpy.c						ft_lstadd.c\
		ft_memccpy.c						ft_memchr.c						ft_strclr.c\
		ft_strstr.c							ft_strnstr.c					ft_strclr.c\
		ft_strchr.c							ft_strrchr.c					ft_strlcat.c\
		ft_strcpy.c							ft_strncpy.c					ft_memmove.c\
		ft_memcmp.c							ft_putchar.c					ft_count_integer.c\
		ft_putchar_fd.c						ft_putstr.c						ft_itoa.c\
		ft_putendl.c						ft_putnbr.c						ft_count_word.c\
		ft_putstr_fd.c						ft_putendl_fd.c					ft_strsplit.c\
		ft_putnbr_fd.c						ft_memalloc.c					ft_strnew.c\
		ft_memdel.c							ft_strnew.c						ft_trimspace.c\
		ft_strdel.c							ft_strclr.c						ft_isword.c\
		ft_striter.c						ft_striteri.c					ft_strtrim.c\
		ft_strmap.c							ft_strmapi.c					ft_strjoin.c					ft_putnendl.c\
		ft_strequ.c							ft_strnequ.c					ft_strsub.c						ft_strchr_index.c

all : $(NAME)

$(NAME): $(SRCO) $(INCLUDES)
		@ar -rc $(NAME) $(SRCO)
		@echo "\033[32m[Your Library is ready]\033[0m"

%.o : %.c
		@gcc $(CFLAGS) -o $@ -c $^
clean :
		@rm -rf $(SRCO)
		@echo "\033[31m[File .o deleted]\033[0m"

fclean : clean
		@rm -rf $(NAME)
		@echo "\033[31m[Libft.a deleted]\033[0m"

re : fclean all

shape :
	@echo "\033[32m.____    .___________________________________\033[0m"
	@echo "\033[32m|    |   |   \______   \_   _____/\__    ___/\033[0m"
	@echo "\033[32m|    |   |   ||    |  _/|    __)    |    |\033[0m"
	@echo "\033[32m|    |___|   ||    |   \|     \     |    |\033[0m"
	@echo "\033[32m|_______ \___||______  /\___  /     |____|\033[0m"
	@echo "\033[32m        \/           \/     \/\033[0m"

.PHONY: clean re all fclean
