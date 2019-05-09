include ../Make.defines

MY_LIBS = mytree.h mytree.c

PROGS =	bubble_sort selectionsort insertionsort mergesort \
		quicksort

all:	${PROGS}

bubble_sort: bubble_sort.o
			${CC} ${CFLAGS} -o $@ bubble_sort.o ${LIBS}

selectionsort: selectionsort.o
			${CC} ${CFLAGS} -o $@ selectionsort.o ${LIBS}

insertionsort: insertionsort.o
			${CC} ${CFLAGS} -o $@ insertionsort.o ${LIBS}

mergesort: mergesort.o
			${CC} ${CFLAGS} -std=c99 -o $@ mergesort.o ${LIBS}

quicksort: quicksort.o
			${CC} ${CFLAGS} -o $@ quicksort.o ${LIBS}

clean:
			rm -f ${PROGS} ${CLEANFILES}
