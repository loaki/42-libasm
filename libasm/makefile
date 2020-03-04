# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 18:06:33 by jfeuilla          #+#    #+#              #
#    Updated: 2020/03/04 18:30:14 by jfeuilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NA			= nasm
NA_FLAGS	= -f macho64
FLAGS		= -Wall -Werror -Wextra
NAME 		= libasm.a

TEST		= test

SRC			= ft_strlen.s\
			  ft_strcpy.s\
			  ft_strcmp.s\
			  ft_write.s\
			  ft_read.s\

OBJ			=	$(SRC:.s=.o)

%.o:			%.s
				$(NA) $(NA_FLAGS) $<

all: $(NAME)

$(NAME): $(OBJ)
		 ar rcs $(NAME) $(OBJ)

test:	$(NAME)
		gcc $(FLAGS) $(NAME) -o $(TEST) main.c
		./$(TEST)
		rm $(TEST)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
