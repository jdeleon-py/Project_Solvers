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
tests: vec_arith_test mat_arith_test 

# MAIN EXE

# TEST EXE
vec_arith_test: vec_arith_test.o vector.o $(INC_DIR)/*.h
	gcc $(CFLAGS) vec_arith_test.o vector.o -o vec_arith_test $(LIBFLAGS)
	echo "Success."

mat_arith_test: mat_arith_test.o matrix.o $(INC_DIR)/*.h
	gcc $(CFLAGS) mat_arith_test.o matrix.o -o mat_arith_test $(LIBFLAGS)
	echo "Success."

# UTILS COMPILE

# SRC COMPILE
vector.o: $(SRC_DIR)/vector.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/vector.c -o vector.o

matrix.o: $(SRC_DIR)/matrix.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(SRC_DIR)/matrix.c -o matrix.o

vec_arith_test.o: $(TEST_DIR)/vec_arith_test.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/vec_arith_test.c -o vec_arith_test.o

mat_arith_test.o: $(TEST_DIR)/mat_arith_test.c $(INC_DIR)/*.h
	gcc -c $(CFLAGS) $(TEST_DIR)/mat_arith_test.c -o mat_arith_test.o

# HOUSEKEEPING
clean:
	rm -f *.o *.gch *~ vec_arith_test mat_arith_test

