# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llejeune <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 11:39:14 by llejeune          #+#    #+#              #
#    Updated: 2019/03/14 19:16:36 by llejeune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = display.c \
	  fractales_move.c \
	  fractales_fixes.c \
	  file_utils.c \
	  initialisation.c \
	  main.c \

OBJ = $(SRC:.c=.o)

SRC_DIR = ./srcs/

OBJ_DIR = ./objs/

SOURCES = $(addprefix $(SRC_DIR), $(SRC))

OBJETS = $(addprefix $(OBJ_DIR), $(OBJ))

FLAG = -Wall -Wextra -Werror

INCLUDES = -I ./include \

LIBFT = ./libft/libft.a

LIBRARIES = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit \
			-L ./libft -lft \

all: $(NAME)

$(NAME): $(OBJETS)
	cc $(FLAG) $(INCLUDES) $(OBJETS) $(LIBRARIES) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIBFT) ./include/fractol.h
	@mkdir $(OBJ_DIR) 2> /dev/null || true
	gcc $(FLAG) $(INCLUDES) -o $@ -c $<

$(LIBFT): FORCE
	make -C ./libft

FORCE:

clean:
	make fclean -C ./libft
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re 
