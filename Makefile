NAME = crenly-b.filler

LIB = -L libft/ -lft

SRCS = 	main.c\
		ft_createmap.c\
		ft_createpiece.c\
		ft_heatmap.c\
		ft_findposition.c\
		ft_get_cor_to_vrm.c\
		ft_supfun.c

OBJS = 	objs/main.o\
		objs/ft_createmap.o\
		objs/ft_createpiece.o\
		objs/ft_heatmap.o\
		objs/ft_findposition.o\
		objs/ft_get_cor_to_vrm.o\
		objs/ft_supfun.o

HEADER = -I includes -I libft/includes

FLAGS = -Wall -Wextra -Werror

.PHONY: all objs make_lib clean fclean re obj

all: $(NAME)

objs/%.o: srcs/%.c includes/filler.h
		gcc $(FLAGS) -c $< -o $@ $(HEADER)

$(NAME) : obj make_lib $(OBJS) libft/libft.a 
	@gcc -o $(NAME) $(OBJS) $(LIB)
	@Echo ✅ Filler compiled!

make_lib:
	@make -C libft

obj:
	@mkdir objs 2> /dev/null || true

clean:
	@make -C libft/ clean
	@rm -rf ./objs/
	@echo 🛀 🛀 🛀 Clean $(NAME)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo 🛀 🛀 🛀 Fclean $(NAME)

re: fclean all