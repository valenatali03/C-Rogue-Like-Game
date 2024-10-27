CC = gcc
CFLAGS = -I/mingw64/include/pdcurses -L/mingw64/lib -lpdcurses -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

# Usa wildcard para encontrar archivos .c
SOURCES = $(wildcard $(SRCDIR)*.c)

all: rogue

rogue: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run: rogue
	./rogue

clean:
	rm -f $(SRCDIR)/*.o rogue
