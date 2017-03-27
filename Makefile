CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pthread
LFLAGS = 
LIBS = 
SOURCES = banker.c banker.h
OBJECTS = $(subst .c,.o,$(SOURCES))
EXE = banker
.PHONY: clean help

banker : banker.c
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

all: $(EXE)

clean:
	rm -f $(OBJECTS) $(EXE) *~

cleanup: 
	rm -f $(OBJECTS) *~