objects=main.o conv.o count.o
gcc3=gcc -g3 -c

rcnv: $(objects)
	gcc -o rcnv $(objects)

main.o: main.c
	$(gcc3) main.c

conv.o: conv.c
	$(gcc3) conv.c

count.o: count.c
	$(gcc3) count.c

clean:
	rm -f *.o

install:
	install rcnv /usr/local/bin

uninstall:
	rm -rf /usr/local/bin/rcnv
