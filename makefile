# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prossi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/25 12:07:08 by prossi            #+#    #+#              #
#    Updated: 2017/06/20 01:24:50 by prossi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = fdf
 
SRC_PATH = src

SRC_NAME = main.c ft_init_struct.c ft_affich.c ft_parsing.c

# OBJ_PATH = $(SRC_PATH)

LDFLAGS = -Lmy_libft
LDLIBS = my_libft/my_libft.a

CC = gcc
CFLAGS = -framework OpenGL -framework Appkit

# OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
# OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(SRC)
	cd my_libft/ ; make re; make clean ; cd ..
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^ $(CFLAGS)

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	cd my_libft/ ; make fclean ; cd .. ; rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
