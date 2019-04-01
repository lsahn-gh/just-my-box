include ../Make.defines

MY_LIBS = mytree.h mytree.c

PROGS =		preorder

all:	${PROGS}
			rm -f *.o

preorder:	preorder.o
			${CC} ${CFLAGS} -o $@ preorder.o ${LIBS} ${MY_LIBS}

clean:
			rm -f ${PROGS} ${CLEANFILES}
