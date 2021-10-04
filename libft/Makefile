NAME			=	libft.a
HEADER			=	libft.h
FILES		=	ft_memccpy.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
        		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
        		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c\
        		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
        		ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
        		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_putchar_fd.c \
        		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strmapi.c\

BONUS 		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
				
OBJS		=	$(patsubst %.c, %.o, $(FILES))

OBJ_BONUS 	= 	$(patsubst %.c, %.o, $(BONUS))

CFLAGS			=	-Wall -Wextra -Werror -c -I

RM				=	rm -f

all: $(NAME) 

$(NAME): $(OBJS) $(HEADER)
		ar rcs $(NAME) $?

bonus: $(OBJ_BONUS) $(HEADER)
		ar rcs $(NAME) $?

%.o : %.c 
	gcc $(CFLAGS) $(HEADER) $< -o $@

clean:
	$(RM) $(OBJS) $(OBJ_BONUS)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus
