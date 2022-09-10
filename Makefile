all: programa

run: programa

programa: main.o tp1.o 
	gcc main.o menu.o sort.o -o programa

main.o: main.c
	gcc -c main.c

menus.o: menu.c menu.h
	gcc -c menu.c 

sort.o: sort.c sort.h
	gcc -c sort.c 

clean:
	rm -r *.o programa