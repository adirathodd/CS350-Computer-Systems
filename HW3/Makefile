OBJS = btof.o ftob.o p6.0
CC = gcc-14
PROGS = btof ftob p6

all:	$(PROGS)

btof:    btof.o
	$(CC) btof.c -o btof
fotb:    ftob.o
	$(CC) ftob.c -o ftob
p6:    p6.o
	$(CC) p6.c -o p6

clean:
	rm *.o *~ ftob btof p6
