# makefile

CC=gcc-14
CFLAGS=-c -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs

all: app

app: main1.o task1.o
	$(CC) main1.o task1.o -o app

main1.o: main1.c task1.h
	$(CC) $(CFLAGS) main1.c 

task1.o: task1.c task1.h
	$(CC) $(CFLAGS) task1.c

cl:
	rm -rf *.o
