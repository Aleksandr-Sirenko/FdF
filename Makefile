# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asirenko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 18:33:38 by asirenko          #+#    #+#              #
#    Updated: 2018/12/17 21:45:34 by asirenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c get_next_line.c read.c move.c count.c minmax.c minmax2.c mashtab.c \
draw.c keys.c keys2.c rotate.c legend.c validate.c color.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(CFLAGS) $(OBJ) -o $(NAME) -l ft -I libft -L libft -L ../mlx \
	-lmlx -framework OpenGL -framework AppKit

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ -I libft -I ../mlx

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
