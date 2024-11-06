# makefile

CC=gcc-14
CFLAGS=-c -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs

all: app

app: main_slow_sort_1.o Simple_sorting_by_exchanges_1.o table.o
	$(CC) main_slow_sort_1.o Simple_sorting_by_exchanges_1.o table.o -o app

main_slow_sort_1.o: main_slow_sort_1.c task1.h
	$(CC) $(CFLAGS) main_slow_sort_1.c

table.o: table.c task1.h
	$(CC) $(CFLAGS) table.c

Simple_sorting_by_exchanges_1.o: Simple_sorting_by_exchanges_1.c task1.h
	$(CC) $(CFLAGS) Simple_sorting_by_exchanges_1.c

cl:
	rm -rf *.o *.dSYM