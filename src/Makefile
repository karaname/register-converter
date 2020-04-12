objects=main.o handlers.o count.o get_buffer.o
pkg=`pkg-config --cflags --libs gtk+-3.0`
gccc=gcc -g3 -c
gcc=gcc -g3

rcnv: $(objects)
	$(gcc) $(pkg) -o rcnv $(objects)

main.o: main.c
	$(gccc) main.c $(pkg)

handlers.o: handlers.c
	$(gccc) handlers.c $(pkg)

count.o: count.c
	$(gccc) count.c $(pkg)

get_buffer.o: get_buffer.c
	$(gccc) get_buffer.c $(pkg)

install:
	install rcnv /usr/local/bin/

uninstall:
	rm -rf /usr/local/bin/rcnv

clean:
	rm -rf *.o
