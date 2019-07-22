NAME = crenly-b.filler

SRCS = 	main.c\
		ft_parsingformap.c\
		ft_piece.c\
		ft_heatmap.c\
		ft_findposition.c\
		ft_supfun.c

OBJ = 	main.o\
		ft_parsingformap.o\
		ft_piece.o\
		ft_heatmap.o\
		ft_findposition.o\
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
