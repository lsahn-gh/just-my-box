include ../Make.defines

MY_LIBS = mytree.h mytree.c

PROGS =	preorder preorder-loop inorder inorder-loop postorder \
		levelorder problem-1and2 problem-3 problem-6 problem-7 \
		problem-8 problem-9 problem-10 problem-11

all:	${PROGS}

preorder:	preorder.o
			${CC} ${CFLAGS} -o $@ preorder.o ${LIBS} ${MY_LIBS}

preorder-loop:	preorder-loop.o
			${CC} ${CFLAGS} -o $@ preorder-loop.o ${LIBS} ${MY_LIBS}

inorder:	inorder.o
			${CC} ${CFLAGS} -o $@ inorder.o ${LIBS} ${MY_LIBS}

inorder-loop:	inorder-loop.o
			${CC} ${CFLAGS} -o $@ inorder-loop.o ${LIBS} ${MY_LIBS}

postorder:	postorder.o
			${CC} ${CFLAGS} -o $@ postorder.o ${LIBS} ${MY_LIBS}

levelorder: levelorder.o
			${CC} ${CFLAGS} -o $@ levelorder.o ${LIBS} ${MY_LIBS}

problem-1and2:	problem-1and2.o
			${CC} ${CFLAGS} -o $@ problem-1and2.o ${LIBS} ${MY_LIBS}

problem-3: problem-3.o
			${CC} ${CFLAGS} -o $@ problem-3.o ${LIBS} ${MY_LIBS}

problem-6: problem-6.o
			${CC} ${CFLAGS} -o $@ problem-6.o ${LIBS} ${MY_LIBS}

problem-7: problem-7.o
			${CC} ${CFLAGS} -o $@ problem-7.o ${LIBS} ${MY_LIBS}

problem-8: problem-8.o
			${CC} ${CFLAGS} -o $@ problem-8.o ${LIBS} ${MY_LIBS}

problem-9: problem-9.o
			${CC} ${CFLAGS} -o $@ problem-9.o ${LIBS} ${MY_LIBS}

problem-10: problem-10.o
			${CC} ${CFLAGS} -o $@ problem-10.o ${LIBS} ${MY_LIBS}

problem-11: problem-11.o
			${CC} ${CFLAGS} -o $@ problem-11.o ${LIBS} ${MY_LIBS}

clean:
			rm -f ${PROGS} ${CLEANFILES}
