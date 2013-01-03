CC=gcc
CFLAGS=-O -g

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: pbfix diff


pbfix: pbfix.o diff.o
	$(CC) $(CFLAGS) -o $@ $^

diff: diff.o
	
pbfix.o: pbfix.c diff.h
diff.o: diff.c diff.h

clean:
	rm -f *.o pbfix diff
