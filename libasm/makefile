# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 18:06:33 by jfeuilla          #+#    #+#              #
#    Updated: 2020/03/04 14:12:41 by jfeuilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NA			= nasm
NA_FLAGS	= -f macho64
FLAGS		= -Wall -Werror -Wextra
NAME 		= libasm.a
OBJ_PATH	= ./obj

TEST		= main.c\

SRC			= ft_strlen.s\

OBJ			=	$(SRC:.s=.o)

%.o:			%.s
				$(NA) $(NA_FLAGS) $<

all: $(NAME)

$(NAME): $(OBJ)
		 ar rcs ${NAME} ${OBJ}

test:	$(NAME)
		gcc $(FLAGS) $(NAME) $(TEST)
		./a.out

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME) $(TEST)

re: fclean all

.PHONY: all clean fclean re
