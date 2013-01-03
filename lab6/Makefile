.PHONY: all clean dist
.SUFFIXES: .c .o .h .asm

all: bcmp

CFLAGS=-g -m32 -O0 -Wall
LDFLAGS=$(CFLAGS)

%.o: %.c
	gcc $(CFLAGS) -c $<
%.o: %.asm
	nasm -g -f elf -o $@ $<

bcmp: bcmp.o bcmpa.o
	gcc $(LDFLAGS) -o $@ $^

bcmp.o: bcmp.c
bcmpa.o : bcmpa.asm

clean:
	rm -f *.o bcmp bcmpa
