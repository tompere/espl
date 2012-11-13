CC=gcc
CFLAGS=-O -g

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: bcmp bfix diff

bcmp: bcmp.o
	$(CC) $(CFLAGS) -o $@ $^

bfix: bfix.o diff.o
	$(CC) $(CFLAGS) -o $@ $^

diff: diff.o
	
bcmp.o: bcmp.c
bfix.o: bfix.c diff.h
diff.o: diff.c diff.h

clean:
	rm -f *.o bcmp bfix diff
