# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/03 18:06:33 by jfeuilla          #+#    #+#              #
#    Updated: 2020/03/10 14:51:23 by jfeuilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NA			= nasm
NA_FLAGS	= -f macho64
FLAGS		= -Wall -Werror -Wextra
NAME 		= libasm.a

TEST		= test

TESTBONUS	= testbonus

SRC			= ft_strlen.s\
			  ft_strcpy.s\
			  ft_strcmp.s\
			  ft_write.s\
			  ft_read.s\
			  ft_strdup.s\

SRC_BONUS	= ft_atoi_base_bonus.s\
			  ft_list_push_front_bonus.s\
			  ft_list_size_bonus.s\
			  ft_list_sort_bonus.s\
			  ft_list_remove_if_bonus.s\

OBJ			= $(SRC:.s=.o)

OBJ_BONUS	= $(SRC_BONUS:.s=.o)

%.o:		%.s
			$(NA) $(NA_FLAGS) $<

all: 		$(NAME)

$(NAME): 	$(OBJ)
		 	ar rcs $(NAME) $(OBJ)

clean:
			rm -rf $(OBJ) $(OBJ_BONUS)

fclean: 	clean
			rm -rf $(NAME) $(BONUS) $(TEST) $(TESTBONUS)

re: 		fclean all

test:		all
			gcc $(FLAGS) $(NAME) -o $(TEST) main.c
			./$(TEST)

bonus:		$(OBJ) $(OBJ_BONUS)
			ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

testbonus:	bonus
			gcc $(FLAGS) $(NAME) -o $(TESTBONUS) main_bonus.c
			./$(TESTBONUS)
