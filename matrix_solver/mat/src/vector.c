// VECTOR STRUCTURE SOURCE FILE
// - JAMES DELEON

#include "vector.h"

/*
typedef struct Vector
{
	const char* filename;
	const char* title;

	int vec_size;
	V_TYPE* arr;
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

	new_vec -> vec_arr = (V_TYPE*)malloc(size * sizeof(V_TYPE));

	// vector array will be populated by corresponding function
	return new_vec;
}

Vector* v_build_file(const char* filename, char* title)
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
	new_vec -> title = title;
	new_vec -> vec_size = n_elements;
	new_vec -> vec_arr = (V_TYPE*)malloc(n_elements * sizeof(V_TYPE));

	// populate vector array
	for(int i = 0; i < n_elements; i++)
	{
		fscanf(vec_file, "%d", &(new_vec -> vec_arr[i]));
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
	printf("\nTitle: %s\n", vec -> title);
	printf("Vector Dim: %u\n", vec -> vec_size);
	printf("---------------\n");
	printf("[ ");
	for(int i = 0; i < vec -> vec_size; i++)
	{
		// TODO: change print type with v_type automatically
		printf(" %d ", vec -> vec_arr[i]);
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
	for(int i = 0; i < vec_sum -> vec_size; i++)
	{
		vec_sum -> vec_arr[i] = vec1 -> vec_arr[i] + vec2 -> vec_arr[i];
	}
	return vec_sum;
}

// return the product of a vector and a scalar
// returns a vector
Vector* v_scal_mult(Vector* vec, int num)
{
	if(vec == NULL)
	{
		printf("Error, vector cannot be found.\n");
		return NULL;
	}

	char* num_str;
	sprintf(num_str, "%d", num);
	char* prod_title = v_make_title(num_str, vec -> title, " * ");

	Vector* vec_scal_prod = v_build(prod_title, vec -> vec_size);
	for(int i = 0; i < vec_scal_prod -> vec_size; i++)
	{
		vec_scal_prod -> vec_arr[i] = num * vec -> vec_arr[i];
	}
	return vec_scal_prod;
}

// returns the dot product of two vectors
// returns a scalar
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
	char* prod_title = v_make_title(vec1 -> title, vec2 -> title, " * ");
	Vector* vec_dot_prod = v_build(prod_title, vec1 -> vec_size);
	for(int i = 0; i < vec_dot_prod -> vec_size; i++)
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

	char* prod_title = v_make_title(vec1 -> title, vec2 -> title, " x ");
	Vector* vec_cross_prod = v_build(prod_title, vec1 -> vec_size);
	if(vec_cross_prod -> vec_size == 1)
	{
		// one-dimensional calculation
	} 
	else if(vec_cross_prod -> vec_size == 2)
	{
		// two-dimensional calculation
	}
	else if(vec_cross_prod -> vec_size == 3)
	{
		// three-dimensional calculation
		//V_TYPE new_x = ;
		//V_TYPE new_y = ;
		//V_TYPE new_z = ;
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
	return vec_cross_prod;
}

// VECTOR OPERATIONS

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