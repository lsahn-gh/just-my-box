include ../Make.defines

MY_LIBS = mytree.h mytree.c

PROGS =	preorder preorder-loop inorder inorder-loop

all:	${PROGS}
			rm -f *.o

preorder:	preorder.o
			${CC} ${CFLAGS} -o $@ preorder.o ${LIBS} ${MY_LIBS}

preorder-loop:	preorder-loop.o
			${CC} ${CFLAGS} -o $@ preorder-loop.o ${LIBS} ${MY_LIBS}

inorder:	inorder.o
			${CC} ${CFLAGS} -o $@ inorder.o ${LIBS} ${MY_LIBS}

inorder-loop:	inorder-loop.o
			${CC} ${CFLAGS} -o $@ inorder-loop.o ${LIBS} ${MY_LIBS}

clean:
			rm -f ${PROGS} ${CLEANFILES}
