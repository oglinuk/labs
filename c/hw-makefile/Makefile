output: main.o say.o
	g++ main.o say.o -o main

main.o: main.c
	g++ -c main.c

say.o: say.c say.h
	g++ -c say.c

clean:
	rm *.o main
