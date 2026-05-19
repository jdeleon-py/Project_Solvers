// VECTOR STRUCTURE HEADER FILE
// - JAMES DELEON

#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define V_TYPE          float
#define V_DIM_MAX       25

typedef struct Vector
{
	const char* filename;

	unsigned int vec_size;
	V_TYPE* vec_arr;
} Vector;

// VECTOR DE/INIT OPERATIONS
Vector* v_build(unsigned int size);
Vector* v_build_file(const char* filename);
void v_print(Vector* vec);
void v_destroy(Vector* vec);

// VECTOR ARITHMETIC OPERATIONS
void v_add(Vector* vec1, Vector* vec2);           // modifies vector one by adding vector 2 to it
void v_scal_mult(Vector* vec, int num);           // modifies vector one by multiplying it by a scalar
V_TYPE v_dot_prod(Vector* vec1, Vector* vec2);    // return the dot product (int) of two vectors 
Vector* v_cross_prod(Vector* vec1, Vector* vec2); // return the cross product of two vectors

// VECTOR OPERATIONS

// VECTOR UTILITY FUNCTIONS

#endif

/* END FILE */