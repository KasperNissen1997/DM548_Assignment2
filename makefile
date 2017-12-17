GCCFLAGS = gcc -Wall
TESTOUT = test/output.txt
RUNTEST = ./string_reader test/
CMPTEST = diff test/correct/

all: string_reader clean test

string_reader: src/string_reader.o src/vector.o
	$(GCCFLAGS) -o string_reader src/string_reader.o src/vector.o

string_reader.o: src/string_reader.c src/vector.h
	$(GCCFLAGS) -c src/string_reader.c

vector.o: src/vector.c src/vector.h
	$(GCCFLAGS) -c src/vector.c

clean:
	rm src/*.o

test: name number length line special

name:
	$(RUNTEST)name.txt > $(TESTOUT)
	$(CMPTEST)name.txt $(TESTOUT)

number:
	$(RUNTEST)number.txt > $(TESTOUT)
	$(CMPTEST)number.txt $(TESTOUT)

length:
	$(RUNTEST)length.txt > $(TESTOUT)
	$(CMPTEST)length.txt $(TESTOUT)

line:
	$(RUNTEST)line.txt > $(TESTOUT)
	$(CMPTEST)line.txt $(TESTOUT)