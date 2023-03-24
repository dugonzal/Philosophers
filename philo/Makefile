# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 23:10:38 by ciclo             #+#    #+#              #
#    Updated: 2023/02/28 12:00:50 by ciclo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= philo

CC			:= clang -g3
FLAGS		:= -Wall -Werror -Wextra
R			:= rm -rf

OBJ_DIR		:= obj/
SRC_DIR		:= src/

SRC_FILES	:= philosofers utils parser

SRC			:= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			:= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -lpthread $(OBJ) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

asm:
	@mkdir -p asm
	@$(CC) $(FLAGS) $(SRC_DIR)* -S
	@mv *.s asm

rm-asm:
	$(R) asm

norm:
	@norminette $(SRC_DIR)*.c $(SRC_DIR)*.h
clean:
	@$(R) $(NAME)

fclean: clean
	@$(R) $(OBJ_DIR)

re: fclean all
