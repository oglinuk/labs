# The ar command creates an archive file. The r flag indicates to update
# the archive if it already exist, the c flag surpresses any warning given,
# and the s flag indicates to write an object-file index into the archive.
output: encrypt.o checksum.o
	sudo ar -rcs /usr/local/lib/libhwstatic.a encrypt.o checksum.o
	gcc main.c -I . -l hwstatic -o main

encrypt.o:
	gcc -c encrypt.c -o encrypt.o

checksum.o:
	gcc -c checksum.c -o checksum.o

clean:
	sudo rm -rf main *.o /usr/local/lib/libhwstatic.a