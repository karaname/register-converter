# variables
objects=main.o handlers.o count.o get_buffer.o
pkg=`pkg-config --cflags --libs gtk+-3.0`
gcc=gcc -g3

# instructions
rcnv: $(objects)
	$(gcc) $(pkg) -o rcnv $(objects)

main.o: main.c
	$(gcc) -c main.c $(pkg)

handlers.o: handlers.c
	$(gcc) -c handlers.c $(pkg)

count.o: count.c
	$(gcc) -c count.c $(pkg)

get_buffer.o: get_buffer.c
	$(gcc) -c get_buffer.c $(pkg)

install:
	install rcnv /usr/local/bin/

uninstall:
	rm -rf /usr/local/bin/rcnv

clean:
	rm -rf *.o
