SRC	=	./source/game.c	\
		./source/setup.c	\
		./source/print.c	\

CFLAGS	=	-g

CON	=	 ${SRC:.c=.o}

NAME	=	tabGame

all:	${NAME}

${NAME}:	${CON}
	ar rc libmy.a ${CON}
	gcc main.c -o ${NAME} -L. -lmy -g

clean:
	rm -f ${CON}

fclean:
	rm -f ${CON}
	rm -f ${NAME}
	rm -f libmy.a

re:	fclean all