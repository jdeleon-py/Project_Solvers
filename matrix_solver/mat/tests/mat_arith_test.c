// MATRIX ARITHMETIC TESTING FILE
// - JAMES DELEON

#include "matrix.h"

#define MAX_MATRICES 1000

int main(int argc, char* argv[])
{
	const char* file1 = "data/mat.txt";
	const char* file2 = "data/mat2.txt";

	Matrix* matrices[MAX_MATRICES];
	int idx = 0;

	Matrix* mat1 = m_build_file(file1);
	m_print(mat1);
	matrices[idx++] = mat1;

	Matrix* mat2 = m_build_file(file2);
	m_print(mat2);
	matrices[idx++] = mat2;

	// m_add test
	Matrix* m_sum = m_add(mat1, mat2);
	m_print(m_sum);
	matrices[idx++] = m_sum;

	// m_scal_mult test
	Matrix* m_scal_prod = m_scal_mult(mat1, 3);
	m_print(m_scal_prod);
	matrices[idx++] = m_scal_prod;

	// m_mat_mult test
	Matrix* m_mat_prod = m_mat_mult(mat1, mat2);
	m_print(m_mat_prod);
	matrices[idx++] = m_mat_prod;

	// clean program memory
	for(int i = 0; i < MAX_MATRICES; i++)
	{
		if(matrices[i] != NULL)
		{
			m_destroy(matrices[i]);
		}
	}

	return 0;
}

/* END FILE */