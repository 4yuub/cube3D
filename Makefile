NAME = cube3D
INC = includes
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit -Ofast -march=native -ffast-math
RM = rm -rf
CC = cc

PARSING = parse.c textures.c identify.c colors.c map.c map_validation.c map_validation_utils.c
RENDERING = render.c event_listener.c raycaster.c dda_algo.c wasd.c loading.c minimap.c
FREE = free_list.c free_data.c
GNL = get_next_line.c get_next_line_utils.c

FILES = cube3d.c \
		$(addprefix parsing/, $(PARSING)) \
		$(addprefix rendering/, $(RENDERING)) \
		$(addprefix gnl/, $(GNL)) \
		$(addprefix free_utils/, $(FREE))
		
SRCS = $(addprefix srcs/, $(FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(MLX) $(OBJS) -o $(NAME)
	@echo "cube3D created"

%.o:%.c $(INC)/cube3d.h
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)
	@echo "compiling..."

clean:
	@$(RM) $(OBJS)
	@echo "successfuly cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "executable removed successfuly"

re: fclean all

