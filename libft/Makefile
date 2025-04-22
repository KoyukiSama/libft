
NAME = libft.a 
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all $(NAME)

$(NAME): main.o
	$(CC) $(CFLAGS) main.o -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
