# Makefile for Converter project

program: main.o conv.o count.o
	gcc -o rcnv main.o conv.o count.o

main.o: main.c
	gcc -g3 -c main.c

conv.o: conv.c
	gcc -g3 -c conv.c

count.o: count.c
	gcc -g3 -c count.c

clean:
	rm -f *.o

install:
	install ./rcnv /usr/local/bin

uninstall:
	rm -rf /usr/local/bin/rcnv
