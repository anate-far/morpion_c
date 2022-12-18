CC = gcc
EXEC = bin/prog
SRCS = srcs/main.c srcs/grid.c
HEADER = includes/
OBJ = ${SRCS:.c=.o}
FLAGS = -Wall -Wextra -Werror

all : ${EXEC}

${EXEC} : ${OBJ}
	${CC} -o ${EXEC} ${OBJ} ${FLAGS} 

%.o : %.c
	${CC} ${FLAGS} -c $< -o $@ -I${HEADER}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${EXEC}
