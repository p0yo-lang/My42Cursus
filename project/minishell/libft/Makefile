CC=			cc

CFLAGS=		-Wall -Werror -Wextra -I./inc

FILENAME=	ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii \
			ft_isdigit ft_isprint ft_itoa ft_memchr ft_memcmp ft_memcpy \
			ft_memmove ft_memset ft_printf ft_putchar_fd ft_putendl_fd \
			ft_putnbr_fd ft_putstr_fd ft_split ft_strchr ft_strdup \
			ft_striteri ft_strjoin ft_strlcat ft_strlcpy ft_strlen \
			ft_strmapi ft_strncmp ft_strnstr ft_strrchr ft_strtrim \
			ft_substr ft_tolower ft_toupper print_char print_hex \
			print_nbr print_ptr print_str utils get_next_line

SOURCEDIR = src/
OBJDIR = obj/

SOURCE = 	$(addprefix $(SOURCEDIR), $(addsuffix .c, $(FILENAME)))
OBJECTS	=	$(addprefix $(OBJDIR), $(addsuffix .o, $(FILENAME)))

NAME = libft.a

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SOURCE)
	gcc -shared -nostartfiles -o libft.so $(OBJECTS)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJDIR)%.o: $(SOURCEDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)
	rm -f libft.so

re: fclean all

.PHONY: all clean fclean re so
