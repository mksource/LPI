include ../Make.defines

PROGS=	prog05_01 prog05_02 prog05_03 prog05_04\
	prog05_05 prog05_06 prog05_07 prog05_08\
	prog05_09
        
all:	${PROGS}

prog05_01:	prog05_01.o
		${CC} ${CFLAGS} -o $@ prog05_01.o ${LIBS}

prog05_02:	prog05_02.o
		${CC} ${CFLAGS} -o $@ prog05_02.o ${LIBS}

prog05_03:	prog05_03.o
		${CC} ${CFLAGS} -o $@ prog05_03.o ${LIBS}

prog05_04:	prog05_04.o
		${CC} ${CFLAGS} -o $@ prog05_04.o ${LIBS}

prog05_05:	prog05_05.o
		${CC} ${CFLAGS} -o $@ prog05_05.o ${LIBS}

prog05_06:      prog05_06.o
		${CC} ${CFLAGS} -o $@ prog05_06.o ${LIBS}

prog05_07:	prog05_07.o
		${CC} ${CFLAGS} -o $@ prog05_07.o ${LIBS}

prog05_08:	prog05_08.o
		${CC} ${CFLAGS} -o $@ prog05_08.o ${LIBS}

prog05_09:	prog05_09.o
		${CC} ${CFLAGS} -o $@ prog05_09.o ${LIBS}

clean:	
	rm -f ${PROGS} ${CLEANFILES}
