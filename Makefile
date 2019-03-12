# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llejeune <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 11:39:14 by llejeune          #+#    #+#              #
#    Updated: 2019/03/12 15:50:38 by llejeune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = display.c \
	  fractales_move.c \
	  fractales_fixes.c \
	  key_mouse.c \
	  main.c \

OBJ = $(SRC:.c=.o)

SRC_DIR = ./srcs/

OBJ_DIR = ./objs/

SOURCES = $(addprefix $(SRC_DIR), $(SRC))

OBJETS = $(addprefix $(OBJ_DIR), $(OBJ))

FLAG = -Wall -Wextra -Werror

INCLUDES = -I ./include \

LIBRARIES = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit \
			-L ./libft -lft \

all: $(NAME)

$(NAME): $(OBJETS)
	make -C ./libft
	cc $(FLAG) $(INCLUDES) $(OBJETS) $(LIBRARIES) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c ./include/fractol.h
	@mkdir $(OBJ_DIR) 2> /dev/null || true
	gcc $(FLAG) $(INCLUDES) -o $@ -c $<

clean:
	make fclean -C ./libft
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re 
