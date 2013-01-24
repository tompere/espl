CC=gcc
CFLAGS=-O -g

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: testnl testfgn canalyze

test: testnl testfgn
	./testnl
	./testfgn


testnl: testnl.o namelist.o
	$(CC) $(CFLAGS) -o $@ $^
testfgn: testfgn.o fgetname.o
	$(CC) $(CFLAGS) -o $@ $^
canalyze: canalyze.o fgetname.o namelist.o
	$(CC) $(CFLAGS) -o $@ $^

testnl.o: testnl.c namelist.h
namelist.o: namelist.c namelist.h
testfgn.o: testfgn.c fgetname.h
fgetname.o: fgetname.c fgetname.h
canalyze.o: canalyze.c fgetname.h namelist.h

clean:
	rm -f testnl testfgn canalyze *.o