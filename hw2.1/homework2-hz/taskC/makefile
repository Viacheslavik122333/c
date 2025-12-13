# makefile

CC=g++
CFLAGS=-c -fstack-protector-all -g -W -Wall -Wfloat-equal -Wwrite-strings -Wcast-align -Wformat-security -Wmissing-format-attribute -Wformat=2 -Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized

all: app

app: mainC.o funC.o headerC.h
	$(CC) mainC.o funC.o -o app

mainC.o: mainC.cpp headerC.h
	$(CC) $(CFLAGS) mainC.cpp

funC.o: funC.cpp headerC.h
	$(CC) $(CFLAGS) funC.cpp

cl:
	rm -rf *.o *.dSYM