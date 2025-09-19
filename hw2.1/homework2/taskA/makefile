# makefile

CC=g++
CFLAGS=-c -fstack-protector-all -g -W -Wall -Wfloat-equal -Wwrite-strings -Wcast-align -Wformat-security -Wmissing-format-attribute -Wformat=2 -Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized

all: app

app: mainA.o funA.o headerA.h
	$(CC) mainA.o funA.o -o app

mainA.o: mainA.cpp headerA.h
	$(CC) $(CFLAGS) mainA.cpp

funA.o: funA.cpp headerA.h
	$(CC) $(CFLAGS) funA.cpp

cl:
	rm -rf *.o *.dSYM