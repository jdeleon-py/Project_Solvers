# MATRIX SOLVER (C) MAKEFILE
# - JAMES DELEON

# PATHS
INC_DIR = inc
SRC_DIR = src
TEST_DIR = tests

# FLAGS
LIBFLAGS = -lm
CFLAGS = -g -I$(INC_DIR) -I$(SRC_DIR) -I$(TEST_DIR)
SDLFLAGS = `/usr/bin/pkg-config sdl2 --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf

# BUILD DIRECTIVES
all: tests
tests: arith_test 

# MAIN EXE

# TEST EXE
arith_test: mat_arith_test.o matrix.o $(INC_DIR)/*.h
	gcc $(CFLAGS) mat_arith_test.o matrix.o -o arith_test $(LIBFLAGS)
	echo "Success."

# UTILS COMPILE

# SRC COMPILE
matrix.o: $(SRC_DIR)/matrix.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/matrix.c -o matrix.o

mat_arith_test.o: $(TEST_DIR)/mat_arith_test.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/mat_arith_test.c -o mat_arith_test.o

# HOUSEKEEPING
clean:
	rm -f *.o *.gch *~ arith_test

