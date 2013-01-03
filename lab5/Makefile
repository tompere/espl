.PHONY: all clean dist
.SUFFIXES: .c .o .h .asm

all: scmp cmpstr

CFLAGS=-g -m32 -O0 -Wall
LDFLAGS=$(CFLAGS)

%.o: %.c
	gcc $(CFLAGS) -c $<
%.o: %.asm
	nasm -g -f elf -o $@ $<

scmp: scmp.o cmpstr.o
	gcc $(LDFLAGS) -o $@ $^

cmpstr:	cmpstr.o
	ld -melf_i386 -g -o $@ $^

scmp.o: scmp.c
cmpstr.o : cmpstr.asm

clean:
	rm -f *.o scmp cmpstr