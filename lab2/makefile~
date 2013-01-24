# The executable 'invert' depends on main only 
invert: invert.o
	cc -o invert invert.o

# Build main.o
invert.o: invert.c
	cc -c invert.c 

# Remove object files, executables (UNIX/Windows), Emacs backup files, and core files
clean:
	rm -rf  *.o invert invert.exe *~ *.core core