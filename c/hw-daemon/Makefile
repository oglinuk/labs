output: main.o daemon.o
	gcc main.o daemon.o -o main

main.o: main.c
	gcc -c main.c

daemon.o: daemon.c daemon.h
	gcc -c daemon.c

clean:
	rm *.o main
