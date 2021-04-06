
FMTDIR=/home/sbjoshi/packages/fmt-7.1.3
INCLUDEDIR=$(FMTDIR)/include
LIBDIR=$(FMTDIR)
CC=g++
CFLAGS=-c -g -Wall -Werror -pedantic -pedantic-errors -I $(INCLUDEDIR)
LIBFLAGS=-lfmt

SRCS=shape.cpp rectangle.cpp circle.cpp  shape_factory.cpp main.cpp
OBJS=$(addsuffix .o,$(basename $(SRCS))) 
EXE=inheritance
.PHONY	: clean all

all : $(EXE)

$(EXE)	: $(OBJS)
		$(CC) -o $@ -L $(LIBDIR) $(OBJS) -lfmt


$(OBJS)	:	%.o	: %.cpp
		$(CC) $(CFLAGS) $<

#rectangle.o : rectangle.cpp rectangle.h
#	$(CC) $(CFLAGS) $<
#
#
#circle.o : circle.cpp circle.h
#	$(CC) $(CFLAGS) $<
#
#shape.o : shape.cpp shape.h
#	$(CC) $(CFLAGS) $<
#
#main.o	: main.cpp shape.h circle.h rectangle.h
#	$(CC) $(CFLAGS) $<
#
clean :
	rm $(OBJS) $(EXE)