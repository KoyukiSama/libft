
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

TEST = $(wildcard test/*.c)
TEST_OUT = $(TEST:.c=.test)

all: $(NAME)

test: $(NAME)
	$(CC) $(CFLAGS) $(TEST) -L. -lft -o $(TEST_OUT)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

testclean:
	rm -f $(TEST_OUT)

testre:
	testclean test