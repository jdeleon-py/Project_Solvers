// VECTOR ARITHMETIC TESTING FILE
// - JAMES DELEON

#include "vector.h"

int main(int argc, char* argv[])
{
	Vector* vec3_1 = v_build_file("data/vec3_1.txt", "vec3_1");
	Vector* vec3_2 = v_build_file("data/vec3_2.txt", "vec3_2");
	v_print(vec3_1);
	v_print(vec3_2);

	// v_add tests

	// v_scal_mult tests

	// v_dot_prod tests

	// v_cross_prod tests


	v_destroy(vec3_1);
	v_destroy(vec3_2);
	return 0;
}

/* END FILE */