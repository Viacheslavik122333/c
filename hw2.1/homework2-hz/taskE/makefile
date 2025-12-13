# makefile

CC=g++
CFLAGS=-c -fstack-protector-all -g -W -Wall -Wfloat-equal -Wwrite-strings -Wcast-align -Wformat-security -Wmissing-format-attribute -Wformat=2 -Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized

all: app

app: mainE.o funE.o headerE.h
	$(CC) mainE.o funE.o -o app

mainE.o: mainE.cpp headerE.h
	$(CC) $(CFLAGS) mainE.cpp

funE.o: funE.cpp headerE.h
	$(CC) $(CFLAGS) funE.cpp

cl:
	rm -rf *.o *.dSYM