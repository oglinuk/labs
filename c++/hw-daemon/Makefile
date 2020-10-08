output: daemon.o main.o
	g++ daemon.o main.o -o main

daemon.o: daemon.hpp daemon.cpp
	g++ -c daemon.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm main *.o