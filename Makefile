# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcaro-ro <mcaro-ro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 19:03:45 by mcaro-ro          #+#    #+#              #
#    Updated: 2024/11/30 02:51:25 by mcaro-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

MINILIBX = -Lminilibx-linux -lmlx_Linux
MINILIBX_FLAGS = -lXext -lX11

NAME = fractol

SOURCE = main.c \
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

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(MINILIBX) $(MINILIBX_FLAGS) -lm -o $(NAME)

all: $(NAME)

runm: re
	@$(MAKE) all $(CFLAGS) --silent;
	./$(NAME) "mandelbrot"

runj: re
	@$(MAKE) all $(CFLAGS) --silent;
	./$(NAME) "julia" "0,285" "0,0"

runb: re
	@$(MAKE) all $(CFLAGS) --silent;
	./$(NAME) "burning_ship"

valgrind: re
	@valgrind ./$(NAME) "mandelbrot"

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norminette: 
	norminette $(NAME).h $(SOURCE)

.DEFAULT_GOAL := all
.PHONY: all clean fclean re run valgrind norminette