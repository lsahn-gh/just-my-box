include ../Make.defines

MY_LIBS = mytree.h mytree.c

PROGS =		preorder	preorder-loop	inorder

all:	${PROGS}
			rm -f *.o

preorder:	preorder.o
			${CC} ${CFLAGS} -o $@ preorder.o ${LIBS} ${MY_LIBS}

preorder-loop:	preorder-loop.o
			${CC} ${CFLAGS} -o $@ preorder-loop.o ${LIBS} ${MY_LIBS}

inorder:	inorder.o
			${CC} ${CFLAGS} -o $@ inorder.o ${LIBS} ${MY_LIBS}

clean:
			rm -f ${PROGS} ${CLEANFILES}
