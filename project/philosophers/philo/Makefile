CC=			cc

CFLAGS=		-Wall -Werror -Wextra -g3 -I./inc -pthread

FILENAME=	main philos_init parse_args dead_flag routine routine_utils

SOURCEDIR = src/
INCDIR = inc/
OBJDIR = obj/

SOURCE = 	$(addprefix $(SOURCEDIR), $(addsuffix .c, $(FILENAME)))
OBJECTS	=	$(addprefix $(OBJDIR), $(addsuffix .o, $(FILENAME)))

NAME = philo

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBDIR)$(LIBNAME).a:
	cd $(LIBDIR) && make

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) 

$(OBJDIR)%.o: $(SOURCEDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TESTDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(TESTDIR)$(NAME)

re: fclean all


.PHONY: all clean fclean re 
