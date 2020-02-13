# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenly-b <crenly-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 15:14:49 by crenly-b          #+#    #+#              #
#    Updated: 2020/02/07 16:39:10 by crenly-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

HEADER = $(addprefix -I , includes/)

SRCS = find_ch ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii \
	ft_isdigit ft_isprint ft_itoa ft_memalloc ft_memccpy ft_memdel \
	ft_memmove ft_memset ft_putchar_fd ft_putchar ft_putendl_fd \
	ft_putendl ft_putnbr_fd ft_putnbr ft_putstr_fd ft_putstr \
	ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdel \
	ft_strdup ft_strequ ft_striter ft_striteri ft_strjoin \
	ft_strlcat ft_strlen ft_strmap ft_strmapi ft_strncat ft_strncmp \
	ft_strncpy ft_strnequ ft_strnew ft_strnstr ft_strrchr \
	ft_strsplit ft_strstr ft_strsub ft_strtrim ft_tolower ft_toupper \
	length_int super_check ft_memcpy ft_memchr ft_memcmp get_next_line

OBJ = $(addprefix obj/, $(addsuffix .o, $(SRCS)))

all: $(NAME)

obj/%.o: src/%.c includes/libft.h
	gcc $(FLAGS) -o $@ -c $< $(HEADER)

$(NAME): obj $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@echo  📖 libft compiled!

obj:
	@mkdir obj  2> /dev/null || true

clean:
	@rm -rf ./obj/

fclean: clean
	@echo 🛀 🛀 🛀 Fclean libft.a
	@rm -f $(NAME)

re: fclean all 

.PHONY: all obj clean fclean re  