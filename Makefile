PROG   = mysynth
LIBS   = -lm
CFLAGS = -Os -Wall
DBGOPT = -g -DDEBUG

SRC = $(wildcard *.c)

all: $(PROG) strip run

$(PROG): $(SRC)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

debug: $(SRC)
	gcc -o $(PROG) $^ $(DBGOPT) $(CFLAGS) $(LIBS) -O0

strip:
	strip -s $(PROG)

run:
	./$(PROG) > raw.bin

clean:
	rm $(PROG)
	rm raw.bin
