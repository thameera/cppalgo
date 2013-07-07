CC=g++
CPPFLAGS=-std=c++0x -g -Wall

SRCS=main.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: sort

sort: $(OBJS)
	$(CC) $(CPPFLAGS) -o sort $(OBJS)

main.o: main.cpp

clean:
	rm -f *.o sort

