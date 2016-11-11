# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghery <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/02 17:11:57 by ghery             #+#    #+#              #
#    Updated: 2016/11/10 16:02:53 by ghery            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FLAG = -Wall -Wextra -Werror

SRC = pars.c wolf.c ray.c key.c draw.c

O_FILE = pars.o wolf.o ray.o key.o draw.o

INC = wolf.h

MLX = -lmlx -lm -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(O_FILE)
	@make -C libft
	@gcc  $(FLAG) $(MLX) -Llibft -lft -I $(INC) -o $(NAME) main.c $(O_FILE)

%.o: %.c
	@gcc $(FLAG) -c $< -I $(INC)

clean:
	rm -rf $(O_FILE)

fclean: clean
	rm -rf $(NAME)
	@make -C libft/ fclean

re: clean fclean all

.PHONY: all clean fclean re
