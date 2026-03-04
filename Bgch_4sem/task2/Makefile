FLAGS1 = -std=c++14 -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format
FLAGS2 = -O3
FLAGS3 = -fsanitize=address

LIBS_H = io_status.h avl_tree.h class.h
LIBS_O = io_status.o

all: a01.out a02.out a03.out a04.out a05.out a06.out a07.out a08.out a09.out

clear:
	rm -f *.o *.out

zip:
	zip Molchanov_VV.zip *.cpp *.h Makefile

rm:
	rm *.out

%.o: %.cpp $(LIBS_H)
	g++ -c $(FLAGS1)  $(FLAGS2)  -lm  $<

%.out: %.o $(LIBS_O)
	g++ $(FLAGS1) $(FLAGS2) $^  -lm  -o $@
