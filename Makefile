CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
LIBFT_DIR = ./libft/*.o
LIBFT = ./libft/libft.a

#LIBFT_SRCS = $(shell find . -name $(LIBFT_DIR))

SRCMODULES_A = so_long.c ft_parsing.c ft_animations.c ft_actions.c img_init.c map_init.c errors.c
SRCMODULES_B = so_long_bonus.c ft_parsing.c ft_animations.c ft_actions.c img_init.c map_init.c errors_bonus.c
OBJMODULES_A = $(patsubst %.c,%.o,$(SRCMODULES_A))
OBJMODULES_B = $(patsubst %.c,%.o,$(SRCMODULES_B))

all : so_long

so_long: $(OBJMODULES_A) $(LIBFT) so_long.h
		$(CC) $(CFLAGS) $(OBJMODULES_A) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o so_long

bonus: $(OBJMODULES_B) $(LIBFT) so_long.h
		$(CC) $(CFLAGS) $(OBJMODULES_B) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o so_long_bonus

.FORCE :

$(LIBFT): .FORCE
	make -C ./libft

clean:
	rm -rf $(OBJMODULES_A) $(OBJMODULES_B)

fclean : clean
	rm -rf so_long so_long_bonus
	
re : fclean all

.PHONY : all clean fclean re