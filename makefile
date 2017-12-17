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

# Cleans the newly created object (.o) files
clean:
	rm src/*.o

# Runs various tests to ensure the correctness of the string_reader executable
test: name number length line

# A sorting test containing different names
name:
	$(RUNTEST)name.txt > $(TESTOUT)
	$(CMPTEST)name.txt $(TESTOUT)

# A sorting test containing different numbers
number:
	$(RUNTEST)number.txt > $(TESTOUT)
	$(CMPTEST)number.txt $(TESTOUT)

# A sorting test containing strings of big lengths
length:
	$(RUNTEST)length.txt > $(TESTOUT)
	$(CMPTEST)length.txt $(TESTOUT)

# A sorting test containing a high amount of strings
line:
	$(RUNTEST)line.txt > $(TESTOUT)
	$(CMPTEST)line.txt $(TESTOUT)