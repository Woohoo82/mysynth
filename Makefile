PROG   = mysynth
LIBS   = -lm
CFLAGS = -Wall

SRC = $(wildcard *.c)

all: $(PROG)

$(PROG): $(SRC)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)
	./$(PROG) > raw.bin

clean:
	rm $(PROG)
	rm raw.bin
