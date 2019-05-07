include ../Make.defines

MY_LIBS = mytree.h mytree.c

PROGS =	bubble_sort selectionsort insertionsort

all:	${PROGS}

bubble_sort: bubble_sort.o
			${CC} ${CFLAGS} -o $@ bubble_sort.o ${LIBS}

selectionsort: selectionsort.o
			${CC} ${CFLAGS} -o $@ selectionsort.o ${LIBS}

insertionsort: insertionsort.o
			${CC} ${CFLAGS} -o $@ insertionsort.o ${LIBS}

clean:
			rm -f ${PROGS} ${CLEANFILES}
