objects=main.o handlers.o count.o buffer.o random.o
pkg=`pkg-config --cflags --libs gtk+-3.0`
gcc=gcc -g3

txma: $(objects)
	$(gcc) $(pkg) -o txma $(objects)

main.o: main.c
	$(gcc) -c main.c $(pkg)

handlers.o: handlers.c
	$(gcc) -c handlers.c $(pkg)

count.o: count.c
	$(gcc) -c count.c $(pkg)

buffer.o: buffer.c
	$(gcc) -c buffer.c $(pkg)

random.o: random.c
	$(gcc) -c random.c $(pkg)

install:
	install txma /usr/local/bin/

uninstall:
	rm -rf /usr/local/bin/txma

clean:
	rm -rf *.o
