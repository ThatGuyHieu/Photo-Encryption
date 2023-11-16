CC = g++
CFLAGS = --std=c++14 -Wall -Werror -pedantic
OBJECTS = main.o PhotoMagic.o FibLFSR.o
TESTOBJ = test.o FibLFSR.o
LIB = -lsfml-graphics -lsfml-window -lsfml-system
LBOOST = -lboost_unit_test_framework

all: PhotoMagic PhotoMagic.a

PhotoMagic: $(OBJECTS)
	$(CC) $(CFLAGS) -o PhotoMagic $(OBJECTS) $(LIB)

main.o: main.cpp PhotoMagic.hpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o $(LIB)

PhotoMagic.a: FibLFSR.o PhotoMagic.o
	ar rcs PhotoMagic.a FibLFSR.o PhotoMagic.o

PhotoMagic.o: PhotoMagic.cpp PhotoMagic.hpp
	$(CC) $(CFLAGS) -c PhotoMagic.cpp -o PhotoMagic.o $(LIB)

FibLFSR.o: FibLFSR.cpp
	$(CC) $(CFLAGS) -c FibLFSR.cpp -o FibLFSR.o

clean:
	rm PhotoMagic test *.o PhotoMagic.a
