# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alam <alam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 14:29:56 by alam              #+#    #+#              #
#    Updated: 2017/06/05 17:37:05 by alam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

FILES = rtv1.c image.c draw.c hooks.c mouse.c init.c color.c init_shapes.c\
		vector_math.c vector_scalar.c vector_ops.c vector_rotate.c intersect.c\
		lighting.c lighting_2.c key.c key_move.c scenes.c

INCLUDES =  -I libft -I minilibx

LIBRARY =  -L libft -lft -L minilibx -lmlx

FRAMEWORK = -framework OpenGL -framework AppKit

OBJECTS = $(FILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

all: libft minilibx $(NAME)

$(NAME):  $(OBJECTS)
	gcc $(CFLAGS) $(INCLUDES) $(LIBRARY) $(FRAMEWORK) -o $(NAME) $(OBJECTS)

libft:
	make -C libft/ all

minilibx:
	make -C minilibx/

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	make -C libft/ fclean
	make -C minilibx/ clean
	rm -f $(NAME)

re: fclean all

new: clean all

.PHONY: all clean fclean re libft minilibx
