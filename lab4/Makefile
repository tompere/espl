.PHONY: all clean dist
.SUFFIXES: .c .o .h .asm

all: scmp

CFLAGS=-g -m32 -O0 -Wall
LDFLAGS=$(CFLAGS)

%.o: %.c
	gcc $(CFLAGS) -c $<

scmp: scmp.o cmpstr.o
	gcc $(LDFLAGS) -o $@ $^

scmp.o: scmp.c
cmpstr.o : cmpstr.c

clean:
	rm -f *.o scmp cmpstr