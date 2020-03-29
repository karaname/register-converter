rcnv: main.o handlers.o count.o get_buffer.o
	gcc -g3 `pkg-config --cflags --libs gtk+-3.0` -o rcnv main.o handlers.o count.o get_buffer.o

main.o: main.c
	gcc -g3 -c main.c `pkg-config --cflags --libs gtk+-3.0`

handlers.o: handlers.c
	gcc -g3 -c handlers.c `pkg-config --cflags --libs gtk+-3.0`

count.o: count.c
	gcc -g3 -c count.c `pkg-config --cflags --libs gtk+-3.0`

get_buffer.o: get_buffer.c
	gcc -g3 -c get_buffer.c `pkg-config --cflags --libs gtk+-3.0`

clean:
	rm -rf *.o
