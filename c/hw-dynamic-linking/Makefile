# NOTE: Need to set LD_LIBRARY_PATH=$PWD/lib and set COUNTRY=US or UK
# I tried to set these environment variables in the Makefile, but didnt work.

# If the shared library is in a custom directory, ld will search various paths,
# including the contents of the environment variable LD_LIBRARY_PATH. The -L flag 
# is to add a directory to the list of directories searched when looking for the
# given library passed to -l. The -l flag is to search the given library when
# linking. An important note is the naming convention of libraries are lib<name>,
# but only <name> is passed to -l.
output: liborder.so main.o
	gcc main.o -L ./lib -l order -o main

# The -I flag is to add a directory to the list of directories to be searched when
# looking for a header file.
main.o:
	gcc -I ./include -c main.c -o main.o


# The -fPIC flag is for creating position-independent code, which means it doesnt matter
# where its loaded into memory. Some operating systems use a technique called memory
# mapping, which means all code is essentially position-independent. The .so extension
# is a shared object file, which is created by passing the -shared flag to gcc. This
# is a dynamic library on Linux.
liborder.so: mkdirs
ifeq (${COUNTRY}, UK)
	gcc -I ./include -fPIC -c order_UK.c -o order.o
else
	gcc -I ./include -fPIC -c order_US.c -o order.o
endif
	gcc -shared order.o -o ./lib/liborder.so

mkdirs:
	mkdir lib include
	cp order.h ./include

clean:
	rm -rf main *.o ./lib ./include