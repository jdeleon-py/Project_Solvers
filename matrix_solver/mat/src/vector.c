// VECTOR STRUCTURE SOURCE FILE
// - JAMES DELEON

#include "vector.h"

/*
typedef struct Vector
{
	const char* filename;
	const char* title;

	int vec_size;
	v_type* arr;
} Vector;
*/

// VECTOR DE/INIT OPERATIONS
Vector* v_build(char* title, unsigned int size)
{
	Vector* new_vec = NULL;

	new_vec = (Vector*)malloc(sizeof(Vector));
	if(new_vec == NULL)
	{
		printf("Error, failed to build vector.\n");
		return NULL;
	}
	new_vec -> filename = NULL;
	new_vec -> title = title;
	new_vec -> vec_size = size;

	new_vec -> vec_arr = (v_type*)malloc(size * sizeof(v_type));

	// vector array will be populated by corresponding function
	return new_vec;
}

Vector* v_build_file(const char* filename);
void v_print(Vector* vec);
void v_destroy(Vector* vec);

// VECTOR ARITHMETIC OPERATIONS
Vector* v_add(Vector* vec1, Vector* vec2)
{
	if(vec1 == NULL || vec2 == NULL)
	{
		printf("Error, vectors cannot be found.\n");
		return NULL;
	}
	if(vec1 -> vec_size != vec2 -> vec_size)
	{
		printf("Error, vector dimensions do not match -- cannot add.\n");
		return NULL;
	}

	char* sum_title = v_make_title(vec1 -> title, vec2 -> title, " + ");
	Vector* vec_sum = v_build(sum_title, vec1 -> vec_size);
	for(int i = 0; i < vec1 -> vec_size; i++)
	{
		vec_sum -> vec_arr[i] = vec1 -> vec_arr[i] + vec2 -> vec_arr[i];
	}
	return vec_sum;
}

Vector* v_scal_mult(Vector* vec, int num);
Vector* v_vec_mult(Vector* vec1, Vector* vec2);

// VECTOR OPERATIONS
v_type v_dot(Vector* vec1, Vector* vec2);      // return dot product of two vectors

// VECTOR UTILITY FUNCTIONS
char* v_make_title(char* v1_title, char* v2_title, char* op)
{
	if(v1_title == NULL || v2_title == NULL || op == NULL)
	{
		printf("Error, title parameters cannot be found.\n");
		return "NULL";
	}

	char* title = (char*)malloc(V_TITLE_MAX * sizeof(char));
	strcpy(title, v1_title);
	strcat(title, op);
	strcat(title, v2_title);
	return title;
}

/* END FILE */