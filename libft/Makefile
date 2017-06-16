# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alam <theandylam@gmail.com>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 17:01:47 by alam              #+#    #+#              #
#    Updated: 2016/11/03 17:01:49 by alam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FT_PRINTF = ft_printf.c conversion_analyze.c number_functions.c get_mods.c \
				print_string.c parse_argument.c number_output_handler.c \
				number_functions2.c string_output_handler.c print_number.c

FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_islower.c ft_isprint.c ft_isupper.c ft_iswhtspc.c \
		ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
		ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
		ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c \
		ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
		ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
		ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
		ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
		ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
		ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		ft_lstmap.c ft_lstaddback.c ft_lstprintstr.c ft_abs.c ft_sqrt.c \
		ft_print_binary.c ft_lstfree.c ft_itoa_base.c ft_wstrsize.c\
		ft_strlower.c ft_strupper.c ft_putwchar.c ft_itoa_base_u.c \
		ft_putwstr.c ft_putnstr.c ft_putnwstr.c ft_wstrlen.c get_next_line.c\
		ft_freesplit.c ft_wstrnsize.c

OBJECTS = $(FILES:.c=.o) $(addprefix ft_printf/, $(FT_PRINTF:.c=.o))

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): message $(OBJECTS)
	@echo "Creating library..."
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "Done"

message:
	@echo "Creating objects..."

%.o: %.c
	@gcc $(CFLAGS) $(INCLUDES) -o $@ -c $^

clean:
	@echo "Removing objects..."
	@rm -f $(OBJECTS)

fclean: clean
	@echo "Removing libft.a..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
