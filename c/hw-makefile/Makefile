output: main.o say.o
	gcc main.o say.o -o main

main.o: main.c
	gcc -c main.c

say.o: say.c say.h
	gcc -c say.c

clean:
	rm *.o main
