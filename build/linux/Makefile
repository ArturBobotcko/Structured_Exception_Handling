# Variable for project root
export ROOT = ~/OS/Structured_Exception_Handling

# Variable for compiler name
COMP = gcc

# Variable for compiler flags
COMPFLAGS = -g3 -O0 -Wall -c

# Variable for preprocessor directive
OS = -D__PL_LINUX__

# Variable for linking
LINKER = $(COMP) -o

main: main.o exception.o
	$(LINKER) main $(ROOT)/src/sources/main.o $(ROOT)/src/sources/exception.o
	mkdir $(ROOT)/bin
	mv main $(ROOT)/bin

main.o: $(ROOT)/src/headers/lib.h
	$(COMP) $(OS) $(COMPFLAGS) $(ROOT)/src/sources/main.c
	mv main.o $(ROOT)/src/sources/

exception.o: $(ROOT)/src/headers/lib.h
	$(COMP) $(OS) $(COMPFLAGS) $(ROOT)/src/sources/exception.c
	mv exception.o $(ROOT)/src/sources/

clean:
	find $(ROOT) -name "*.o" | xargs rm -rf
	find $(ROOT) -name "*.d" | xargs rm -rf
	rm -rf $(ROOT)/bin