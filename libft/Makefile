
NAME         := libft.a
CC           := gcc
CFLAGS       := -Wall -Wextra -Werror

SRC     := $(wildcard *.c)
OBJ     := $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
	$(MAKE) clean