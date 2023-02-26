# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 23:10:38 by ciclo             #+#    #+#              #
#    Updated: 2023/02/26 10:54:47 by ciclo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= philosofers

CC			:= clang -g3

FLAGS		:= -Wall -Werror -Wextra
R			:= rm -rf
OBJ_DIR		:= obj/
SRC_DIR		:= src/

SRC_FILES	:= main

#SRC			:= $(($(addprefix $(SRC_DIR)), $(addsufix( .c $(OBJ_DIR)) .o)))
#OBJ			:= $(addprefix, $(SRC_DIR) .c, $(addsufix(OBJ_DIR), .o))
SRC			:= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			:= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))


all: $(NAME) $(OBJ)


$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo "$@ done compile"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@
	@echo "$@ done compile"

$(OBJ_DIR):
	@mkdir -p $@



clean:
	$(R) $(NAME)

fclean: clean
	$(R) $(OBJ_DIR)

re: fclean all

.PHONY:

