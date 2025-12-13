# makefile

CC=g++
CFLAGS=-c -fstack-protector-all -g -W -Wall -Wfloat-equal -Wwrite-strings -Wcast-align -Wformat-security -Wmissing-format-attribute -Wformat=2 -Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized

all: app

app: mainB.o funB.o headerB.h
	$(CC) mainB.o funB.o -o app

mainB.o: mainB.cpp headerB.h
	$(CC) $(CFLAGS) mainB.cpp

funB.o: funB.cpp headerB.h
	$(CC) $(CFLAGS) funB.cpp

cl:
	rm -rf *.o *.dSYM