NAME = fractol
NAME_BONUS = fractol_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
RM = rm -f

MLX = -lmlx
APPKIT = -framework AppKit
OPENGL = -framework OpenGL

SRC = mandatory/main.c mandatory/complex.c mandatory/render.c mandatory/events.c mandatory/utils.c
SRC_BONUS = bonus/main_bonus.c bonus/complex_bonus.c bonus/render_bonus.c bonus/events_bonus.c bonus/utils_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

mandatory/%.o: mandatory/%.c mandatory/fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/fractol_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX) $(APPKIT) $(OPENGL) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) $(MLX) $(APPKIT) $(OPENGL) -o $(NAME_BONUS)

bonus : $(NAME_BONUS)

clean :
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

.PHONY: clean