CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

LIBFT_SRCS = $(shell find . -name '*.c')

SRCMODULES_A = so_long.c ft_pars_map.c
OBJMODULES_A = $(patsubst %.c,%.o,$(SRCMODULES_A))

all : so_long

so_long: $(OBJMODULES_A) $(LIBFT) so_long.h
		$(CC) $(CFLAGS) $(OBJMODULES_A) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o so_long

$(LIBFT): $(LIBFT_SRCS)
	make -C ./libft

clean:
	rm -rf $(OBJMODULES_A)

fclean : clean
	rm -rf so_long
	
re : fclean all

.PHONY : all clean fclean re