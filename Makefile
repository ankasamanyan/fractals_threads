# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akasaman <akasaman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 18:48:15 by ankasamanya       #+#    #+#              #
#    Updated: 2022/09/02 13:51:01 by akasaman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC =	fract-ol.c input.c the_math.c \
		colour.c hooks.c mandelbrot.c zoom.c \
		move_it.c julia.c burningship.c mlx_random.c

OBJ =	$(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf
MV = mv

LIBFT =	./Libft/libft.a

MLX =	libmlx.a -framework OpenGL -framework AppKit -o

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[92m•\033[0m\c"

$(NAME): $(OBJ) $(SRC)
	@$(MAKE) -C mlx
	@$(MV) mlx/libmlx.a mlx/..
	@$(MAKE) bonus -C Libft
	@$(CC) $(FLAGS) $(OBJ) $(MLX) $(NAME) $(LIBFT)
	@echo "\033[92m\nFract-ol successfully compiled!\033[0m"

clean:
	@$(MAKE) fclean -C Libft
	@$(RM) $(OBJ) $(BONUS_OBJ) libmlx.a
	@echo "\033[0;31mFract-ol successfully cleaned!\033[0m"

fclean: clean
	@($(RM) $(NAME))

re: fclean all

.PHONY: all clean fclean re