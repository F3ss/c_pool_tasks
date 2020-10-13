all: obj
	${CC} ${FLAGS} -o ${NAME} ${OBJF}

NAME = printProg

SRC = main.c print.c

OBJF = main.o print.o

obj:
	${CC} ${FLAGS} -c ${SRC}

CC = cc

FLAGS = -Wall -Werror -Wextra

clean:
	rm -rf *.o

fclean: clean
	rm -rf ${NAME} ${NAMELIB}

re: fclean all
