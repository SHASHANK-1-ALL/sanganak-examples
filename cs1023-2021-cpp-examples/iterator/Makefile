EXE=iterator
SRCS=main.cpp
OBJS=$(addsuffix .o,$(basename $(SRCS)))
CC=/usr/bin/g++
CFLAGS=-Wall -Werror -pedantic -std=c++20
.PHONY	: clean all
all	:	$(SRCS)
	$(CC) $(CFLAGS) -o $(EXE) $(SRCS)

clean : 
	rm -f $(EXE) $(OBJS)
