CC=g++
OBJ=dcc
CFLAGS=-lglut -lGLU -lGL

.PHONY: compile run clean

compile:
	$(CC) -o $(OBJ) dynamic_circular_coords.cpp $(CFLAGS)

run:
	./$(OBJ)

clean:
	rm $(OBJ)

