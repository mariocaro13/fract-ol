# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 19:03:45 by mcaro-ro          #+#    #+#              #
#    Updated: 2024/12/13 19:57:55 by mcaro-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3  #-fsanitize=address

MINILIBX_DIR = minilibx-linux
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx_Linux.a
MINILIBX = -L$(MINILIBX_DIR) -lmlx_Linux
MINILIBX_FLAGS = -lXext -lX11

NAME = fractol

SOURCE = main.c \
	utils.c \
	atoi_float.c \
	str_utils.c \
	mlx_utils.c \
	mlx_events.c \
	math_utils.c \
	init.c \
	render.c \
	view_control.c \
	mandelbrot.c \
	julia.c \
	burning_ship.c
	
OBJECTS = $(SOURCE:.c=.o)

%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

$(NAME): $(MINILIBX_LIB) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(MINILIBX) $(MINILIBX_FLAGS) -lm -o $(NAME)

$(MINILIBX_LIB):
	@$(MAKE) -C $(MINILIBX_DIR)

all: $(NAME)

runm: re
	@$(MAKE) all --silent;
	./$(NAME) "mandelbrot"

runj: re
	@$(MAKE) all --silent;
	./$(NAME) "julia" "0.285" "0.0"

runb: re
	@$(MAKE) all --silent;
	./$(NAME) "burning_ship"

valgrind: re
	valgrind ./$(NAME) mandelbrot

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norminette: 
	norminette $(NAME).h $(SOURCE)

.DEFAULT_GOAL := all
.PHONY: all clean fclean re run valgrind norminette