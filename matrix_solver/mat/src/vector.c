// VECTOR STRUCTURE SOURCE FILE
// - JAMES DELEON

#include "vector.h"

/*
typedef struct Vector
{
	const char* filename;

	int vec_size;
	V_TYPE* arr;
} Vector;
*/

// VECTOR DE/INIT OPERATIONS
Vector* v_build(unsigned int size)
{
	Vector* new_vec = NULL;

	new_vec = (Vector*)malloc(sizeof(Vector));
	if(new_vec == NULL)
	{
		printf("Error, failed to build vector.\n");
		return NULL;
	}
	new_vec -> filename = NULL;
	new_vec -> vec_size = size;
	new_vec -> vec_arr = (V_TYPE*)malloc(size * sizeof(V_TYPE));

	// vector array will be populated by corresponding function
	return new_vec;
}

Vector* v_build_file(const char* filename)
{
	unsigned int n_elements;
	FILE* vec_file = NULL;
	Vector* new_vec = NULL;

	// open vector file to read dimensions
	vec_file = fopen(filename, "r");
	if(vec_file == NULL)
	{
		printf("Error, file could not be opened.\n");
		return NULL;
	}
	fscanf(vec_file, "%d\n", &n_elements);

	// initialize vector structure from file
	new_vec = (Vector*)malloc(sizeof(Vector));
	new_vec -> filename = filename;
	new_vec -> vec_size = n_elements;
	new_vec -> vec_arr = (V_TYPE*)malloc(n_elements * sizeof(V_TYPE));

	// populate vector array
	for(int i = 0; i < n_elements; i++)
	{
		fscanf(vec_file, "%f", &(new_vec -> vec_arr[i]));
	}
	fclose(vec_file);
	return new_vec;
}

void v_print(Vector* vec)
{
	if(vec == NULL)
	{
		printf("Error, vector cannot be found.\n");
		return;
	}
	printf("Vector Dim: %u\n", vec -> vec_size);
	printf("---------------\n");
	printf("[ ");
	for(int i = 0; i < vec -> vec_size; i++)
	{
		// TODO: change print type with v_type automatically
		printf(" %.3f ", vec -> vec_arr[i]);
	}
	printf("]\n");
}

void v_destroy(Vector* vec)
{
	if(vec == NULL || vec -> vec_arr == NULL)
	{
		printf("Error, vector cannot or vector array could not be found.\n");
		return;
	}
	free(vec -> vec_arr);
	free(vec);
}

// VECTOR ARITHMETIC OPERATIONS
// ----------------------------

// return the sum of two vectors
void v_add(Vector* vec1, Vector* vec2)
{
	if(vec1 == NULL || vec2 == NULL)
	{
		printf("Error, vectors cannot be found.\n");
		return;
	}
	if(vec1 -> vec_size != vec2 -> vec_size)
	{
		printf("Error, vector dimensions do not match -- cannot add.\n");
		return;
	}
	for(int i = 0; i < vec1 -> vec_size; i++)
	{
		vec1 -> vec_arr[i] += vec2 -> vec_arr[i];
	}
	return;
}

// return the product of a vector and a scalar
void v_scal_mult(Vector* vec, int num)
{
	if(vec == NULL)
	{
		printf("Error, vector cannot be found.\n");
		return;
	}
	for(int i = 0; i < vec -> vec_size; i++)
	{
		vec -> vec_arr[i] *= num;
	}
	return;
}

// returns the dot product of two vectors
V_TYPE v_dot_prod(Vector* vec1, Vector* vec2)
{
	if(vec1 == NULL || vec2 == NULL)
	{
		printf("Error, vectors cannot be found.\n");
		return -1;
	}
	if(vec1 -> vec_size != vec2 -> vec_size)
	{
		printf("Error, dimensions do not match -- cannot compute dot product.\n");
		return -1;
	}
	V_TYPE dot_prod = 0;
	for(int i = 0; i < vec1 -> vec_size; i++)
	{
		dot_prod += vec1 -> vec_arr[i] * vec2 -> vec_arr[i];
	}
	return dot_prod;
}

// returns the cross product of two vectors
// returns a vector orthogonal to the input vectors
// for now, only compute the cross product up to (including) three dimensions
Vector* v_cross_prod(Vector* vec1, Vector* vec2)
{
	if(vec1 == NULL || vec2 == NULL)
	{
		printf("Error, vectors cannot be found.\n");
		return NULL;
	}
	if(vec1 -> vec_size != vec2 -> vec_size)
	{
		printf("Error, dimensions do not match -- cannot compute cross product.\n");
		return NULL;
	}
	Vector* vec_cross_prod = NULL;
	V_TYPE new_x, new_y, new_z;
	V_TYPE* vec1_arr = vec1 -> vec_arr;
	V_TYPE* vec2_arr = vec2 -> vec_arr;
	if(vec1 -> vec_size == 1)
	{
		// one-dimensional calculation is undefined
		printf("Error, dimensionality is too low.\n");
		return NULL;
	} 
	else if(vec1 -> vec_size == 2)
	{
		// two-dimensional calculation (returns 3D vector)
		vec_cross_prod = v_build(3);
		new_x = 0;
		new_y = 0;
		new_z = (vec1_arr[0] * vec2_arr[1]) - (vec1_arr[1] * vec2_arr[0]);
	}
	else if(vec_cross_prod -> vec_size == 3)
	{
		// three-dimensional calculation of a x b
		vec_cross_prod = v_build(3);
		//V_TYPE new_x = aybz - azby;
		new_x = (vec1_arr[1] * vec2_arr[2]) - (vec1_arr[2] * vec2_arr[1]);
		//V_TYPE new_y = axbz - azbx;
		new_y = (vec1_arr[0] * vec2_arr[2]) - (vec1_arr[2] * vec2_arr[0]);
		//V_TYPE new_z = axby - aybx;
		new_z = (vec1_arr[0] * vec2_arr[1]) - (vec1_arr[1] * vec2_arr[0]);
	}
	else
	{
		// needs higher dimensional math, populate with zero vector for now
		printf("Error, computation requires a higher dimensional implementation.\n");
		for(int i = 0; i < vec_cross_prod -> vec_size; i++)
		{
			vec_cross_prod -> vec_arr[i] = 0;
		}
	}
	vec_cross_prod -> vec_arr[0] = new_x;
	vec_cross_prod -> vec_arr[1] = new_y;
	vec_cross_prod -> vec_arr[2] = new_z;
	return vec_cross_prod;
}

// VECTOR OPERATIONS
V_TYPE v_mag(Vector* vec)
{
	if(vec == NULL)
	{
		printf("Error, vector cannot be found -- cannot compute magnitude.\n");
		return -1;
	}
	return 0;
}

// VECTOR UTILITY FUNCTIONS

/* END FILE */