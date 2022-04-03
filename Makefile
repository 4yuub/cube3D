NAME = cube3D
INC = includes
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
RM = rm -rf
CC = cc

PARSING = parse.c

FILES = cube3d.c \
		$(addprefix parsing/, $(PARSING))
		
SRCS = $(addprefix srcs/, $(FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(MLX) $(OBJS) -o $(NAME)
	@echo "cube3D created"

%.o:%.c $(INC)/cube3d.h
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)
	@echo "compiling..."

clean:
	@$(RM) $(OBJS)
	@echo "successfuly cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "executable removed successfuly"

re: fclean all

