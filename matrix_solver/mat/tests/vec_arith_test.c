// VECTOR ARITHMETIC TESTING FILE
// - JAMES DELEON

#include "vector.h"

int main(int argc, char* argv[])
{
	// loading 2-dimensional vectors
	Vector* vec2_1 = v_build_file("data/vec2_1.txt");
	Vector* vec2_2 = v_build_file("data/vec2_2.txt");
	v_print(vec2_1);
	v_print(vec2_2);

	// loading 3-dimensional vectors
	Vector* vec3_1 = v_build_file("data/vec3_1.txt");
	Vector* vec3_2 = v_build_file("data/vec3_2.txt");
	v_print(vec3_1);
	v_print(vec3_2);

	// v_add tests
	v_add(vec2_1, vec2_2);
	v_print(vec2_1);

	// this incantaion should throw an error
	v_add(vec3_1, vec2_1);
	v_print(vec3_1);

	// adding 3D vectors
	v_add(vec3_1, vec3_2);
	v_print(vec3_1);

	// v_scal_mult tests
	int scal1 = -2; 
	int scal2 = 3;
	int scal3 = 0;

	v_scal_mult(vec2_1, scal1);
	v_print(vec2_1);

	// v_dot_prod tests
	V_TYPE v_dprod2 = v_dot_prod(vec2_1, vec2_2);
	printf("Dot product: %f\n", v_dprod2);

	// this incantation should throw an error
	V_TYPE v_dprod23 = v_dot_prod(vec2_1, vec3_1);
	printf("Dot product: %f\n", v_dprod23);

	V_TYPE v_dprod3 = v_dot_prod(vec3_1, vec3_2);
	printf("Dot product: %f\n", v_dprod3);

	// v_cross_prod tests


	// clean up used vectors
	v_destroy(vec2_1);
	v_destroy(vec2_2);
	v_destroy(vec3_1);
	v_destroy(vec3_2);

	printf("\nEND PROGRAM.\n");
	return 0;
}

/* END FILE */