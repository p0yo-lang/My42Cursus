CC=cc
CFLAGS=-Wall -Werror -Wextra
SOURCE=$(wildcard *.c)
OBJECTS=$(SOURCE:.c=.o)
NAME=libft.a

all: $(NAME)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SOURCE)
	gcc -shared -nostartfiles -o libft.so $(OBJECTS)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
