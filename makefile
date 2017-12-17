GCCFLAGS = gcc -Wall
GDBFLAGS = gdb --args
SRCPATH = src/
TESTPATH = test/

all: string_reader

string_reader: src/string_reader.o src/vector.o
	$(GCCFLAGS) -o string_reader src/string_reader.o src/vector.o

string_reader.o: src/string_reader.c src/vector.h
	$(GCCFLAGS) -c src/string_reader.c

vector.o: src/vector.c src/vector.h
	$(GCCFLAGS) -c src/vector.c

clean:
	rm src/*.o

testNames:
	./string_reader test/testName.txt > test/testNameOutput.txt