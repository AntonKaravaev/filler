NAME = filler_visual

LIB = libft.a -L ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

SRCS = 	main.c\
		solution.c\
		initial.c\
		menu.c\
		draw.c\
		lines.c\
		print.c\
		print_sup1.c\

OBJS = 	objs/main.o\
		objs/solution.o\
		objs/initial.o\
		objs/menu.o\
		objs/draw.o\
		objs/lines.o\
		objs/print.o\
		objs/print_sup1.o\


HEADER = -I includes

FLAGS = -Wall -Wextra -Werror

.PHONY: all objs clean fclean re obj make_lib

all: $(NAME)

objs/%.o: srcs/%.c includes/filler_visual.h
		gcc $(FLAGS) -c $< -o $@ $(HEADER)

$(NAME) : obj make_lib $(OBJS) minilibx_macos/libmlx.a
	@gcc -o $(NAME) $(OBJS) $(LIB)
	@Echo ✅ $(NAME) compiled!

make_lib:
	@make -C minilibx_macos

obj:
	@mkdir objs 2> /dev/null || true

clean:
	@rm -rf ./objs/
	@make -C ./minilibx_macos clean
	@echo 🛀 🛀 🛀 Clean $(NAME)

fclean: clean
	@rm -f $(NAME)
	@make -C ./minilibx_macos fclean
	@echo 🛀 🛀 🛀 Fclean $(NAME)

re: fclean all

##  $@ — имя .o-файла (Имя файла цели правила. В шаблонном правиле с несколькими целями,имя той цели, которая вызвала выполнение команд правила.)
##  $< — имя .cpp-файла (Имя первой зависимости. Если цель получила свои команды из неявного правила, то это будет первая зависимость, добавленная неявным правилом.)