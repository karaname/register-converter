rcnv: main.o buttons.o count.o
	gcc -g3 `pkg-config --cflags --libs gtk+-3.0` -o rcnv main.o buttons.o count.o

main.o: main.c
	gcc -g3 -c main.c `pkg-config --cflags --libs gtk+-3.0`

buttons.o: buttons.c
	gcc -g3 -c buttons.c `pkg-config --cflags --libs gtk+-3.0`

count.o: count.c
	gcc -g3 -c count.c `pkg-config --cflags --libs gtk+-3.0`

clean:
	rm -rf *.o
