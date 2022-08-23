IDIR = .
CC=g++.exe
CFLAGS=-I $(IDIR)
OUTPUT=main

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

OBJ = main.cpp 
output: $(OBJ)
	$(CC) $(OBJ) -o $(OUTPUT) $(CFLAGS) 
