// MATRIX ARITHMETIC TESTING FILE
// - JAMES DELEON

#include "matrix.h"

#define MAX_MATRICES 1000

int main(int argc, char* argv[])
{
	const char* file1 = "data/mat.txt";
	const char* file2 = "data/mat2.txt";

	Matrix* matrices[MAX_MATRICES];
	int i = 0;

	Matrix* mat1 = m_build_file(file1);
	m_print(mat1);
	matrices[i++] = mat1;

	Matrix* mat2 = m_build_file(file2);
	m_print(mat2);
	matrices[i++] = mat2;

	// m_add test
	Matrix* m_sum = m_add(mat1, mat2);
	m_print(m_sum);
	matrices[i++] = m_sum;

	// clean program memory
	m_destroy(mat1);
	m_destroy(mat2);
	m_destroy(m_sum);

	return 0;
}

/* END FILE */