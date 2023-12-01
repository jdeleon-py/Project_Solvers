// MATRIX STRUCTURE SOURCE FILE
// - JAMES DELEON

#include "matrix.h"

// MATRIX DE/INIT UTILITIES
Matrix* m_build(unsigned int n_rows, unsigned int n_cols)
{
	Matrix* new_mat = NULL;

	new_mat = (Matrix*)malloc(sizeof(Matrix));
	if(new_mat == NULL)
	{
		printf("Error, failed to build matrix.\n");
		return NULL;
	}
	new_mat -> rows = n_rows;
	new_mat -> cols = n_cols;
	new_mat -> dim = (n_rows == n_cols) ? n_rows : 0;

	new_mat -> arr = (m_type**)malloc(n_rows * sizeof(m_type*));
	for(int i = 0; i < n_rows; i++)
	{
		new_mat -> arr[i] = (m_type*)malloc(n_cols * sizeof(m_type));
	}

	// matrix array will be populated by corresponding function
	return new_mat;
}

Matrix* m_build_file(const char* filename)
{
	unsigned int num_rows, num_cols;
	FILE* mat_file = NULL;
	Matrix* new_matrix = NULL;

	// open file to read matrix dimensions
	mat_file = fopen(filename, "r");
	if(mat_file == NULL)
	{
		printf("File could not be opened.\n");
		return NULL;
	}
	fscanf(mat_file, "%d %d\n", &num_rows, &num_cols);

	// initialize matrix structure from file
	new_matrix = (Matrix*)malloc(sizeof(Matrix));
	new_matrix -> filename = filename;
	new_matrix -> rows = num_rows;
	new_matrix -> cols = num_cols;
	new_matrix -> dim = (num_rows == num_cols) ? num_rows : 0;

	new_matrix -> arr = (m_type**)malloc(num_rows * sizeof(m_type*));
	for(int i = 0; i < num_rows; i++)
	{
		new_matrix -> arr[i] = (m_type*)malloc(num_cols * sizeof(m_type));
	}
	
	// populate the matrix array
	for(unsigned int r = 0; r < num_rows; r++)
	{
		for(unsigned int c = 0; c < num_cols; c++)
		{
			fscanf(mat_file, "%d", &(new_matrix -> arr[r][c]));
		}
	}
	fclose(mat_file);
	return new_matrix;
}

void m_print(Matrix* mat)
{
	if(mat == NULL)
	{
		printf("Error, can not print matrix.\n");
		return;
	}
	int r, c;

	printf("\n   |");
	for(c = 0; c < mat -> cols; c++) printf("%8d|", c);
	printf("\n----");
	for(c = 0; c < mat -> cols; c++) printf("---------");
	printf("\n");
	for(r = 0; r < mat -> rows; r++)
	{
		printf("  %d|", r);
		for(int c = 0; c < mat -> cols; c++) printf("%7d| ", mat -> arr[r][c]);
		printf("\n");
	}
}

void m_destroy(Matrix* mat)
{
	if(mat == NULL)
	{
		printf("Error, can not find matrix.\n");
		return;
	}

	for(int r = 0; r < mat -> rows; r++)
	{
		free(mat -> arr[r]);
	}
	free(mat -> arr);
	free(mat);
}

// MATRIX ARITHMETIC UTILITIES
Matrix* m_add(Matrix* mat1, Matrix* mat2)
{
	if(mat1 == NULL || mat2 == NULL)
	{
		printf("Error, matrices cannot be found.\n");
		return NULL;
	}
	if((mat1 -> rows != mat2 -> rows) || (mat1 -> cols != mat2 -> cols))
	{
		printf("Error, matrix dimensions do not match -- cannot add.\n");
		return NULL;
	}

	Matrix* mat_sum = m_build(mat1 -> rows, mat2 -> cols);
	for(int r = 0; r < mat_sum -> rows; r++)
	{
		for(int c = 0; c < mat_sum -> cols; c++)
		{
			mat_sum -> arr[r][c] = mat1 -> arr[r][c] + mat2 -> arr[r][c];
		}
	}
	return mat_sum;
}

Matrix* m_scal_mult(Matrix* mat, int num)
{
	if(mat == NULL || mat -> arr == NULL)
	{
		printf("Error, matrix can not be found.\n");
		return NULL;
	}

	Matrix* mat_prod = m_build(mat -> rows, mat -> cols);
	for(int r = 0; r < mat_prod -> rows; r++)
	{
		for(int c = 0; c < mat_prod -> cols; c++)
		{
			mat_prod -> arr[r][c] = num * mat -> arr[r][c];
		}
	}
	return mat_prod;
}

Matrix* m_mat_mult(Matrix* mat1, Matrix* mat2)
{
	if(mat1 == NULL || mat2 == NULL)
	{
		printf("Error, can not find matrices.\n");
		return NULL;
	}
	if(mat1 -> cols != mat2 -> rows)
	{
		printf("Error, matrix dimensions do not align -- can not multiply.\n");
		return NULL;
	}

	Matrix* mat_prod = m_build(mat1 -> rows, mat2 -> cols);
	for(int r = 0; r < mat1 -> rows; r++)
	{
		for(int c = 0; c < mat2 -> cols; c++)
		{
			m_type res_num = 0;
			for(int k = 0; k < mat1 -> cols; k++)
			{
				res_num += mat1 -> arr[r][k] * mat2 -> arr[k][c];
			}
			mat_prod -> arr[r][c] = res_num;
		}
	}
	return mat_prod;
}

// LINEAR MATRIX OPERATIONS
Matrix* m_rref(Matrix* mat)
{
	if(mat == NULL)
	{
		printf("Error (rref), can not find matrix.\n");
		return NULL;
	}

	Matrix* rref_mat = m_build(mat -> rows, mat -> cols);
	unsigned int i, lead = 0;
	m_type val;
	for(int r = 0; r < mat -> rows; r++)
	{
		if(mat -> cols <= lead)
		{
			break;
		}

		i = r;
		while(mat -> arr[i][lead] == 0)
		{
			i++;
			if(i == mat -> rows)
			{
				i = r;
				lead++;
				if(mat -> cols == lead)
				{
					return rref_mat;
				}
			}
		}
		m_row_swap(mat, i, r);
		val = mat -> arr[r][lead];
		m_row_scale(mat, r, 1 / val);


	}
}

Matrix* m_inv(Matrix* mat);

// RETURN MATRIX* OR VOID???
Matrix* m_adj(Matrix* mat)
{
	// in a field of real-numbers, adj(T) = transpose(T)
	// for a real-valued matrix

	if(mat == NULL || mat -> arr == NULL)
	{
		printf("Error (adj), can not find matrix.\n");
		return NULL;
	}

	Matrix* mat_adj = m_build(mat -> rows, mat -> cols);
	m_type temp_val;
	unsigned int r, c;

	// TODO: OPTIMIZE THIS
	// new array is populated with old array
	for(r = 0; r < mat -> rows; r++)
	{
		for(c = 0; c < mat -> cols; c++)
		{
			mat_adj -> arr[r][c] = mat -> arr[r][c];
		}
	}

	// operates on a matrix in-place
	for(r = 0; r < mat -> rows; r++)
	{
		for(c = r + 1; c < mat -> cols; c++)
		{
			temp_val = mat_adj -> arr[r][c];
			mat_adj -> arr[r][c] = mat_adj -> arr[c][r];
			mat_adj -> arr[c][r] = temp_val;
		}
	}

	// in a field of complex-numbers, adj(T) = conjugate-transpose(T)

	return mat_adj;
}

// return a rotated matrix by 90 deg clockwise
Matrix* m_rot(Matrix* mat)
{
	if(mat == NULL || mat -> arr == NULL)
	{
		printf("Error (rot), matrix can not be found.\n");
		return NULL;
	}

	// build return matrix
	// transpose original matrix
	Matrix* mat_rot = m_adj(mat);

	// reverse ordering of each row
	for(int r = 0; r < mat_rot -> rows; r++)
	{
		m_row_rev(mat_rot -> arr[r], mat_rot -> cols);
	}
	return mat_rot;
}

int m_det(Matrix* mat)
{
	/*
	if(mat -> rows != mat -> cols)
	{
		printf("Error, not a square matrix -- cannot compute determinant.\n");
		return -1;
	}
	unsigned int dim = mat -> rows;
	m_type temp_mat[dim][dim];
	int det = 0;

	if(dim == 1)
	{
		det = mat -> arr[0][0];
	}
	else if(dim == 2)
	{
		det = (mat -> arr[0][0] * mat -> arr[1][1]) - (mat -> arr[0][1] * mat -> arr[1][0]);
	}
	else
	{
		for(int i = 0; i < dim; i++)
		{
			int h = 0, k = 0;
			for(int row_idx = 1; row_idx < dim; row_idx++)
			{
				for(int col_idx = 0; col_idx < dim; col_idx++)
				{
					if(col_idx == i) continue;
					temp_mat[h][k] = mat -> arr[row_idx][col_idx];
					k++;
					if(k == dim - 1)
					{
						h++;
						k = 0;
					}
				}
			}
			det = det + mat -> arr[0][p] * pow(-1, p) * m_det(temp_mat, dim - 1);
		}
	}
	return det;
	*/
}

int m_tr(Matrix* mat)
{
	if(mat == NULL)
	{
		printf("Error -- tr(), matrix can not be found.\n");
		return -1;
	}

	int trace = 0;
	for(int i = 0; i < mat -> rows; i++)
	{
		trace += mat -> arr[i][i];
	}
	return trace;
}

// - RREF UTILITIES
void m_row_swap(Matrix* mat, unsigned int row1, unsigned int row2)
{
	m_type* temp_row = mat -> arr[row1];
	mat -> arr[row1] = mat -> arr[row2];
	mat -> arr[row2] = temp_row;
}

void m_row_add(Matrix* mat, unsigned int row_src, unsigned int row_dest, m_type num)
{
	for(int i = 0; i < mat -> cols; i++)
	{
		mat -> arr[row_dest][i] += num * mat -> arr[row_src][i];
	}
}

void m_row_scale(Matrix* mat, unsigned int row, m_type num)
{
	for(int i = 0; i < mat -> cols; i++)
	{
		mat -> arr[row][i] *= num;
	}
}

// - ROTATION UTILITIES
void m_row_rev(int* row, int row_size)
{
	int start = 0, end = row_size - 1;
	m_type temp_val;

	// reverse the order of elements in the row
	// slide a window from the edges towards the middle
	while(start < end)
	{
		temp_val = row[start];
		row[start] = row[end];
		row[end] = temp_val;

		start++; end--;
	}
}

/* END FILE */