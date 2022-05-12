NAME = sample.out
LIBFTNAME = libft.a
LIBFTPATH = ./libft
MLXPATH = ./mlx
SRC = main.c  create_map.c init_map.c render.c
OBJ = $(SRC:.c=.o)

# /* ~~~~~~~ INCLUDING GNL ~~~~~~~ */
GNL_DIR = ./gnl/
GNL = get_next_line.c \
	get_next_line_utils.c \

GNL_OBJS = ${addprefix ${GNL_DIR}, ${GNL:.c=.o}}


FLAGS = -Wall -Wextra -Werror -g
LINKS = -lmlx -framework OpenGL -framework AppKit
MLB_FLAGS	= -I -g -L /usr/X11/lib -L./mlbx -lmlx -Imlx -lXext -lX11 -lz -lm


NONE='\033[0m'
GREEN='\033[32m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJ) $(GNL_OBJS)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@make -C ${LIBFTPATH}
	@gcc $(FLAGS) $(OBJ) $(GNL_OBJS) $(LINKS) ./libft/libft.a -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)
	@rm $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     Deleted object files" $(NONE)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	gcc $(FLAGS) -c $(SRC)

exe: all
	@echo "     - Executing $(NAME)... \n"
	@./$(NAME)
	@echo "\n     - Done -"

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)

re: fclean all
