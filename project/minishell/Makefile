CC=						cc

CFLAGS=					-Wall -Werror -Wextra -g3 -I./inc -I$(LIB_DIR)inc -lreadline -lcurses

SRCS=					main
PARSING_SRCS=			lexer token_utils token_buffer token_redirection

SOURCE_DIR=				src/
INC_DIR= 				inc/
OBJ_DIR= 				obj/
LIB_DIR= 				libft/

PARSING_DIR=			$(SOURCE_DIR)parsing/
PARSING_OBJ_DIR=		$(OBJ_DIR)parsing/

EXECUTION_DIR=			$(SOURCE_DIR)execution/
EXECUTION_OBJ_DIR=		$(OBJ_DIR)execution/


SOURCES = 				$(addprefix $(SOURCE_DIR), $(addsuffix .c, $(SRCS))) \
						$(addprefix $(PARSING_DIR), $(addsuffix .c, $(PARSING_SRCS)))

OBJECTS	=				$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS))) \
						$(addprefix $(PARSING_OBJ_DIR), $(addsuffix .o, $(PARSING_SRCS)))

LIB_NAME =				libft
NAME = 					minishell

all: $(OBJ_DIR) $(PARSING_OBJ_DIR) $(NAME) $(LIB_DIR)$(LIB_NAME).a

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(PARSING_OBJ_DIR):
	mkdir -p $(PARSING_OBJ_DIR)

$(EXECUTION_OBJ_DIR):
	mkdir-p $(EXECUTION_OBJ_DIR)

$(LIB_DIR)$(LIB_NAME).a:
	make -C libft 

$(NAME): $(OBJECTS) $(LIB_DIR)$(LIB_NAME).a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIB_DIR)$(LIB_NAME).a

$(OBJ_DIR)%.o: $(SOURCE_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(PARSING_OBJ_DIR)%.o: $(PARSING_DIR)%.c | $(PARSING_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re