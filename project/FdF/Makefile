CC=			cc

CFLAGS=		-Wall -Werror -Wextra -g3 -MMD -MP -I./inc -I$(LIBDIR)inc 

FILENAME =	main parse utils draw geometry draw_lines parse_utils
SOURCEDIR = src/
INCDIR = 	inc/
OBJDIR = 	obj/
LIBDIR = 	libft/
TESTDIR = 	test/
LIBNAME = 	libft

SOURCE = 	$(addprefix $(SOURCEDIR), $(addsuffix .c, $(FILENAME)))
OBJECTS	=	$(addprefix $(OBJDIR), $(addsuffix .o, $(FILENAME)))
DEPS = 		$(OBJECTS:.o=.d)

NAME = 		fdf

all: $(OBJDIR) $(NAME)

test: all
	mkdir -p test
	mv $(NAME) $(TESTDIR)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBDIR)$(LIBNAME).a:
	cd $(LIBDIR) && make

$(NAME): $(OBJECTS) $(LIBDIR)$(LIBNAME).a 
	$(CC) $(OBJECTS) $(CFLAGS) $(LIBDIR)$(LIBNAME).a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJDIR)%.o: $(SOURCEDIR)%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@


clean:
	rm -rf $(OBJDIR) $(TESTDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(TESTDIR)$(NAME)
	cd $(LIBDIR) && rm -rf $(OBJDIR) $(TESTDIR) $(LIBNAME).a

-include $(DEPS)

re: fclean all
	cd $(LIBDIR) && make re

.PHONY: all clean fclean re 
