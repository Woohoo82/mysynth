PROG   = mysynth
LIBS   = -lm
CFLAGS = -Os -Wall

SRC = $(wildcard *.c)

all: $(PROG) strip run

$(PROG): $(SRC)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

strip:
	strip -s $(PROG)

run:
	./$(PROG) > raw.bin

clean:
	rm $(PROG)
	rm raw.bin
