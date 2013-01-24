CC=gcc
CFLAGS=-O -g
# The executable 'invert' depends on main only 
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: invert

invert: invert.o
	$(CC) $(CFLAGS) -o $@ $^

# Build main.o
invert.o: invert.c

# Remove object files, executables (UNIX/Windows), Emacs backup files, and core files
clean:
	rm -rf  *.o invert