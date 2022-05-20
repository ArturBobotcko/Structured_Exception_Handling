main: main.o exception.o
	gcc ../../src/sources/main.o ../../src/sources/exception.o -o main
	mkdir ../../bin
	mv main ../../bin

main.o: ../../src/headers/lib.h
	gcc -D__PL_LINUX__ -g3 -O0 -Wall -c ../../src/sources/main.c
	mv main.o ../../src/sources/

exception.o: ../../src/headers/lib.h
	gcc -D__PL_LINUX__ -g3 -O0 -Wall -c ../../src/sources/exception.c
	mv exception.o ../../src/sources/

clean:
	rm -rf ../../src/sources/*.o ../../bin