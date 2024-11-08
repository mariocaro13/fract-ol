# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcaro-ro <mcaro-ro@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 19:03:45 by mcaro-ro          #+#    #+#              #
#    Updated: 2024/11/08 13:18:27 by mcaro-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

MINILIBX = -Lminilibx-linux -lmlx_Linux
MINILIBX_FLAGS = -lXext -lX11

NAME = fractol

SOURCE = main.c \
	ft_mlx.c \
	utility.c \
	mandelbrot.c
	
OBJECTS = $(SOURCE:.c=.o)

%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(MINILIBX) $(MINILIBX_FLAGS) -o $(NAME)

all: $(NAME)

run: re
	@$(MAKE) all $(CFLAGS) --silent;
	./$(NAME)

valgrind: re
	@valgrind ./$(NAME)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

norminette: 
	norminette $(NAME).h $(SOURCE)

.DEFAULT_GOAL := all
.PHONY: all clean fclean re run valgrind norminette