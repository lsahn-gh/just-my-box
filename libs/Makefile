include ../Make.defines

LIB_OBJS = xz-queue.o xz-tree.o

all:	${LIB_OBJS}
			ar rv ${LIBXZ_PATH} $?
			${RANLIB} ${LIBXZ_PATH}
			rm -f ${LIB_OBJS}

clean:
			rm -f *.a
