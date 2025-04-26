
NAME	:= libft.a
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror

SRC		:= ft_ctype1.c ft_ctype2.c \
			ft_mem1.c ft_mem2.c \
			ft_stlib.c \
			ft_str1.c ft_str2.c ft_str3.c
OBJ		:= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
	$(MAKE) clean

.PHONY: all clean fclean re