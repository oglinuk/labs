output: main.o hello.o
	g++ main.o hello.o -o main

main.o: main.cpp
	g++ -c main.cpp

hello.o: hello.cpp hello.h
	g++ -c hello.cpp

clean:
	rm *.o main