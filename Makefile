CC=gcc
CFLAGS=-Wall

OUT=bin
BIN=softshell
SRC=src

all: compile

compile: ${OUT}
	${CC} ${CFLAGS} -o ${OUT}/${BIN} ${SRC}/softshellv2.c

${OUT}:
	mkdir ${OUT}

clean:
	rm -rf ${OUT}
