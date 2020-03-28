rcnv: main.o handlers.o
	gcc -g3 `pkg-config --cflags --libs gtk+-3.0` -o rcnv main.o handlers.o

main.o: main.c
	gcc -g3 -c main.c `pkg-config --cflags --libs gtk+-3.0`

handlers.o: handlers.c
	gcc -g3 -c handlers.c `pkg-config --cflags --libs gtk+-3.0`

clean:
	rm -rf *.o
