// VECTOR STRUCTURE HEADER FILE
// - JAMES DELEON

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define V_TYPE int

#define V_DIM_MAX     25
#define V_TITLE_MAX  100

typedef struct Vector
{
	const char* filename;
	char* title;

	unsigned int vec_size;
	V_TYPE* vec_arr;
} Vector;

// VECTOR DE/INIT OPERATIONS
Vector* v_build(char* title, unsigned int size);
Vector* v_build_file(const char* filename, char* title);
void v_print(Vector* vec);
void v_destroy(Vector* vec);

// VECTOR ARITHMETIC OPERATIONS
Vector* v_add(Vector* vec1, Vector* vec2);        // return the sum of two vectors
Vector* v_scal_mult(Vector* vec, int num);        // return the product of a vector and a scalar
V_TYPE v_dot_prod(Vector* vec1, Vector* vec2);    // return the dot product of two vectors
Vector* v_cross_prod(Vector* vec1, Vector* vec2); // return the cross product of two vectors

// VECTOR OPERATIONS

// VECTOR UTILITY FUNCTIONS
char* v_make_title(char* v1_title, char* v2_title, char* op);

#endif

/* END FILE */