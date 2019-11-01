all: main.o library.o linked_list.o
	gcc -o program main.o library.o linked_list.o

main.o: main.c linked_list.h
	gcc -c main.c

library.o: library.c library.h
	gcc -c library.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

run:
	./program

clean:
	rm *.o
