// MATRIX STRUCTURE HEADER FILE
// - JAMES DELEON

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define m_type int
#define MAX_DIM 25

typedef struct 
{
	const char* filename;
	unsigned int dim, rows, cols;
	m_type** arr;
} Matrix;

// MATRIX DE/INIT OPERATIONS
Matrix* m_build(unsigned int n_rows, unsigned int n_cols);
Matrix* m_build_file(const char* filename);
void m_print(Matrix* mat);
void m_destroy(Matrix* mat);

// MATRIX ARITHMETIC OPERATIONS
Matrix* m_add(Matrix* mat1, Matrix* mat2);
Matrix* m_scal_mult(Matrix* mat, int num);
Matrix* m_mat_mult(Matrix* mat1, Matrix* mat2);

// MATRIX OPERATIONS
Matrix* m_rref(Matrix* mat);
Matrix* m_inv(Matrix* mat);
Matrix* m_adj(Matrix* mat);
int m_det(Matrix* mat);
int m_tr(Matrix* mat);
int m_dot(Matrix* mat);

// MATRIX UTILITY FUNCTIONS

// - RREF UTILITIES
void m_row_swap(Matrix* mat, unsigned int row1, unsigned int row2);
void m_row_add(Matrix* mat, unsigned int row_src, unsigned int row_dest, m_type num);
void m_row_scale(Matrix* mat, unsigned int row, m_type num);

#endif

/* END FILE */