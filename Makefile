COMPILER = gcc
CFLAGS = -Wall --pedantic

NAME = gauss
BINS_FOLDER = bin

SRCS = backsubst.c gauss.c mat_io.c main.c
SRCS_FOLDER = src
OBJS_FOLDER = src
OBJS = src/backsubst.o src/gauss.o src/mat_io.o src/main.o

all: ${BINS_FOLDER}/${NAME}
	
${BINS_FOLDER}/${NAME}: ${OBJS}
	${COMPILER} ${CFLAGS} $^ -o $@

%.o: %.c
	${COMPILER} ${CFLAGS} -c $< -o $@

test: all
	bin/gauss dane/A dane/b

test_more: all
	bin/gauss dane/A1 dane/b1
	bin/gauss dane/A2 dane/b2
	bin/gauss dane/A3 dane/b3
	bin/gauss dane/A4 dane/b4
	bin/gauss dane/A5 dane/b5

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${BINS_FOLDER}/*

re: fclean all

.PHONY: all test test_more clean fclean re
