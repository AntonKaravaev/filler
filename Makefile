NAME = crenly-b.filler

SRCS = 	main.c\
		ft_createmap.c\
		ft_createpiece.c\
		ft_heatmap.c\
		ft_findposition.c\
		ft_get_cor_to_vrm.c\
		ft_supfun.c

OBJ = 	main.o\
		ft_createmap.o\
		ft_createpiece.o\
		ft_heatmap.o\
		ft_findposition.o\
		ft_get_cor_to_vrm.o\
		ft_supfun.o

INC = includes/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	@make -C libft
	@gcc $(FLAGS) -c $(SRCS) -I ./libft
	@gcc $(OBJ) -L libft/ -lft -o $(NAME) -g

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
