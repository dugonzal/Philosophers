# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 23:10:38 by ciclo             #+#    #+#              #
#    Updated: 2023/04/01 22:51:14 by ciclo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= philo

CC			:= clang -g3
FLAGS		:= -Wall -Werror -Wextra
R			:= rm -rf

OBJ_DIR		:= obj/
SRC_DIR		:= src/

SRC_FILES	:= philo utils utils2 parser threads mutex actions

SRC			:= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			:= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

ifndef verbose
.SILENT:
endif

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -lpthread $(OBJ) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

asm:
	mkdir -p asm
	$(CC) $(FLAGS) $(SRC_DIR)* -S
	mv *.s asm

rm-asm:
	$(R) asm

norm:
	norminette $(SRC_DIR)*.c include/*.h

clean:
	$(R) $(NAME)

fclean: clean
	$(R) $(OBJ_DIR)

re: fclean all

val: all
	valgrind --leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--verbose \
		--log-file=valgrind-out.txt \
		./$(NAME) 4 800 200 200

.PHONY: all clean fclean re asm rm-asm norm
