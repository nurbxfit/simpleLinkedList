IDIR	= ../include
CPP	= g++
CC	= gcc
CFLAGS	= -I$(IDIR)

ODIR	= ./obj
LDIR	=../lib

LIBS=-lm

DEPS	= function.h,unorderlist.h,orderlist.h,carinfo.h,linklist.h
#DEPS	= $(patsubst %,$(IDIR)/%,$(_DEPS))

OBJ	= main.o function.o
#OBJ	= $(patsubst %,$(ODIR)/%,$(_OBJ))



$(ODIR)/%.o: %.c $(DEPS)
	$(CPP) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CPP) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

