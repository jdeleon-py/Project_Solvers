// VECTOR STRUCTURE HEADER FILE
// - JAMES DELEON

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define v_type int
#define V_MAX_DIM 25

typedef struct Vector
{
	const char* filename;
	const char* title;

	int vec_size;
	v_type* arr;
} Vector;

// VECTOR DE/INIT OPERATIONS
Vector* v_build(unsigned int size);
Vector* v_build_file(const char* filename);
void v_print(Vector* vec);
void v_destroy(Vector* vec);

// VECTOR ARITHMETIC OPERATIONS
Vector* v_add(Vector* vec1, Vector* vec2);
Vector* v_scal_mult(Vector* vec, int num);
Vector* v_vec_mult(Vector* vec1, Vector* vec2);

// VECTOR OPERATIONS
v_type v_dot(Vector* vec1, Vector* vec2);      // return dot product of two vectors

// VECTOR UTILITY FUNCTIONS


#endif

/* END FILE */