# makefile

CC=gcc-14
CFLAGS=-c -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs

all: app

app: main.o fun.o
	$(CC) main.o fun.o -o app

main.o: main.c header.h
	$(CC) $(CFLAGS) main.c

fun.o: fun.c header.h
	$(CC) $(CFLAGS) fun.c

cl:
	rm -rf *.o *.dSYM