CC=						cc

CFLAGS=					-Wall -Werror -Wextra -g3 -I./inc -I$(LIB_DIR)inc
LDFLAGS= 				-lreadline -lcurses

SRCS=					main
LEXER_SRCS=				lexer token_utils token_buffer token_redirection
PARSER_SRCS=			parser

SOURCE_DIR=				src/
INC_DIR= 				inc/
OBJ_DIR= 				obj/
LIB_DIR= 				libft/

PARSING_DIR=			$(SOURCE_DIR)parsing/
PARSING_OBJ_DIR=		$(OBJ_DIR)parsing/
LEXER_DIR=				$(PARSING_DIR)lexer/
PARSER_DIR=				$(PARSING_DIR)parser/

EXECUTION_DIR=			$(SOURCE_DIR)execution/
EXECUTION_OBJ_DIR=		$(OBJ_DIR)execution/


SOURCES = 				$(addprefix $(SOURCE_DIR), $(addsuffix .c, $(SRCS))) \
						$(addprefix $(LEXER_DIR), $(addsuffix .c, $(LEXER_SRCS))) \
						$(addprefix $(PARSER_DIR), $(addsuffix .c, $(PARSER_SRCS)))

OBJECTS	=				$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRCS))) \
						$(addprefix $(PARSING_OBJ_DIR), $(addsuffix .o, $(LEXER_SRCS))) \
						$(addprefix $(PARSING_OBJ_DIR), $(addsuffix .o, $(PARSER_SRCS)))

LIB_NAME =				libft
NAME = 					minishell

all: $(OBJ_DIR) $(PARSING_OBJ_DIR) $(NAME) $(LIB_DIR)$(LIB_NAME).a

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(PARSING_OBJ_DIR):
	mkdir -p $(PARSING_OBJ_DIR)

$(EXECUTION_OBJ_DIR):
	mkdir -p $(EXECUTION_OBJ_DIR)

$(LIB_DIR)$(LIB_NAME).a:
	make -C libft 

$(NAME): $(OBJECTS) $(LIB_DIR)$(LIB_NAME).a
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJECTS) $(LIB_DIR)$(LIB_NAME).a

$(OBJ_DIR)%.o: $(SOURCE_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(PARSING_OBJ_DIR)%.o: $(LEXER_DIR)%.c | $(PARSING_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(PARSING_OBJ_DIR)%.o: $(PARSER_DIR)%.c | $(PARSING_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re