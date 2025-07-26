DIRSRC = ./source/

DIRINC	= ./include/

DIROBJ	= ./objs/

DIRLIB	= ./libft/

SRC		= ft_printf print_char print_hex print_nbr print_ptr print_str utils

SRCS	= $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

HEAD	= ./include/ 

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

NAMELFT	= libft.a

CC		= cc
RM		= rm -f
AR		= ar rc
RN		= ranlib

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c -I${DIRINC} -I${DIRLIB} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			cd ${DIRLIB} && ${MAKE} && cp -v ${NAMELFT} ../${NAME}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

all:		$(NAME)

clean:
			${RM} ${OBJS}
			cd ${DIRLIB} && ${MAKE} clean

fclean:		clean
			${RM} $(NAME)
			cd ${DIRLIB} && ${MAKE} fclean

re:			fclean all

.PHONY:		all clean fclean re