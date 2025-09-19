# makefile

CC=g++
CFLAGS=-c -fstack-protector-all -g -W -Wall -Wfloat-equal -Wwrite-strings -Wcast-align -Wformat-security -Wmissing-format-attribute -Wformat=2 -Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized

all: app

app: mainF.o funF.o headerF.h
	$(CC) mainF.o funF.o -o app

mainF.o: mainF.cpp headerF.h
	$(CC) $(CFLAGS) mainF.cpp

funF.o: funF.cpp headerF.h
	$(CC) $(CFLAGS) funF.cpp

cl:
	rm -rf *.o *.dSYM