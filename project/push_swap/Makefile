CC=				cc

CFLAGS=			 -Wall -Wextra -Werror -g3 -I./inc -I$(LIBDIR)/inc 

FILENAME=		main
OP_FILES=		push swap rotate reverse_rotate
SORT_FILES=		sort_utils quicksort radixsort small_sort radix_sort_utils chunksort
STACK_FILES=	stack_utils
PARSE_FILES=	parse parse_utils int_max

SOURCEDIR = 	src/
OPDIR = 		$(SOURCEDIR)operations/
SORTDIR = 		$(SOURCEDIR)sort/
STACKDIR = 		$(SOURCEDIR)stack/
PARSEDIR = 		$(SOURCEDIR)parse/
OPOBJDIR = 		$(OBJDIR)operations/
SORTOBJDIR = 	$(OBJDIR)sort/
STACKOBJDIR = 	$(OBJDIR)stack/
PARSEOBJDIR = 	$(OBJDIR)parse/
INCDIR = 		inc/
OBJDIR = 		obj/
LIBDIR = 		libft/
TESTDIR = 		test/
LIBNAME = 		libft

SOURCE = 		$(addprefix $(SOURCEDIR), $(addsuffix .c, $(FILENAME))) \
				$(addprefix $(OPDIR), $(addsuffix .c, $(OP_FILES))) \
				$(addprefix $(SORTDIR), $(addsuffix .c, $(SORT_FILES))) \
				$(addprefix $(STACKDIR), $(addsuffix .c, $(STACK_FILES))) \
				$(addprefix $(PARSEDIR), $(addsuffix .c, $(PARSE_FILES)))

			

OBJECTS	=		$(addprefix $(OBJDIR), $(addsuffix .o, $(FILENAME))) \
				$(addprefix $(OPOBJDIR), $(addsuffix .o, $(OP_FILES))) \
				$(addprefix $(SORTOBJDIR), $(addsuffix .o, $(SORT_FILES))) \
				$(addprefix $(STACKOBJDIR), $(addsuffix .o, $(STACK_FILES))) \
				$(addprefix $(PARSEOBJDIR), $(addsuffix .o, $(PARSE_FILES)))


NAME = 			push_swap


all: $(OBJDIR) $(OPOBJDIR) $(SORTOBJDIR) $(STACKOBJDIR) $(PARSEOBJDIR) $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OPOBJDIR):
	mkdir -p $(OPOBJDIR)

$(SORTOBJDIR):
	mkdir -p $(SORTOBJDIR)

$(STACKOBJDIR):
	mkdir -p $(STACKOBJDIR)

$(PARSEOBJDIR):
	mkdir -p $(PARSEOBJDIR)

$(LIBDIR)$(LIBNAME).a:
	cd $(LIBDIR) && make

$(NAME): $(OBJECTS) $(LIBDIR)$(LIBNAME).a 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBDIR)$(LIBNAME).a

$(OBJDIR)%.o: $(SOURCEDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OPOBJDIR)%.o: $(OPDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SORTOBJDIR)%.o: $(SORTDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(STACKOBJDIR)%.o: $(STACKDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(PARSEOBJDIR)%.o: $(PARSEDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)
	cd $(LIBDIR) && make fclean

re: fclean all
	cd $(LIBDIR) && make re

.PHONY: all clean fclean re
