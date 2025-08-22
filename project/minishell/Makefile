CC=					cc

CFLAGS=				-Wall -Werror -Wextra -g3 -I./inc -I$(LIBDIR)inc -lreadline -lcurses

FILENAME=			main
PARSINGFILENAME=	parsing

SOURCEDIR=			src/
INCDIR= 			inc/
OBJDIR= 			obj/
LIBDIR= 			libft/

PARSINGDIR=			$(SOURCEDIR)parsing/
PARSINGOBJDIR=		$(OBJDIR)parsing/

SOURCE = 			$(addprefix $(SOURCEDIR), $(addsuffix .c, $(FILENAME))) \
					$(addprefix $(PARSINGDIR), $(addsuffix .c, $(PARSINGFILENAME)))

OBJECTS	=			$(addprefix $(OBJDIR), $(addsuffix .o, $(FILENAME))) \
					$(addprefix $(PARSINGOBJDIR), $(addsuffix .o, $(PARSINGFILENAME)))

LIBNAME =			libft
NAME = 				minishell

all: $(OBJDIR) $(PARSINGOBJDIR) $(NAME) $(LIBDIR)$(LIBNAME).a

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(PARSINGOBJDIR):
	mkdir -p $(PARSINGOBJDIR)

$(LIBDIR)$(LIBNAME).a:
	cd $(LIBDIR) && make

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBDIR)$(LIBNAME).a

$(OBJDIR)%.o: $(SOURCEDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PARSINGOBJDIR)%.o: $(PARSINGDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TESTDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(TESTDIR)$(NAME)

re: fclean all


.PHONY: all clean fclean re