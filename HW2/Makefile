OBJS = p1.o p2.o p3.o p4.0 p6.0
CC = gcc-14
PROGS = p1 p2 p3 p4 p6

all:	$(PROGS)

p1:    p1.o
	$(CC) p1.c -o p1
p2:    p2.o
	$(CC) p2.c -o p2
p3:    p3.o
	$(CC) p3.c -o p3
p4:    p4.o
	$(CC) p4.c -o p4
p6:    p6.o
	$(CC) p6.c -o p6

clean:
	rm *.o *~ p1 p2 p3 p4 p6
