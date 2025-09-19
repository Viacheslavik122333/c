# makefile

CC=g++
CFLAGS=-c -fstack-protector-all -g -W -Wall -Wfloat-equal -Wwrite-strings -Wcast-align -Wformat-security -Wmissing-format-attribute -Wformat=2 -Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized

all: app

app: mainD.o funD.o headerD.h
	$(CC) mainD.o funD.o -o app

mainD.o: mainD.cpp headerD.h
	$(CC) $(CFLAGS) mainD.cpp

funD.o: funD.cpp headerD.h
	$(CC) $(CFLAGS) funD.cpp

cl:
	rm -rf *.o *.dSYM