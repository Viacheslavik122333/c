FLAGS1 = -std=c++14 -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual
FLAGS2 = -O3
FLAGS3 = -fsanitize=address

LIBS_H = io_status.h doubly_linked_list.h condition.h command.h record.h ordering.h operation.h
LIBS_O = command.o io_status.o record.o

all: a.out

zip:
	zip Molchanov_VV.zip *.cpp *.h Makefile

rm:
	rm -f *.out

%.o: %.cpp $(LIBS_H)
	g++ -c $(FLAGS1) $(FLAGS2) $<

%.out: %.o $(LIBS_O)
	g++ $(FLAGS1) $(FLAGS2) $^  -lm  -o $@