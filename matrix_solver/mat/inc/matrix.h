// MATRIX STRUCTURE HEADER FILE
// - JAMES DELEON

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "vector.h"

#define m_type int
#define M_MAX_DIM 25

typedef struct Matrix
{
	const char* title;
	const char* filename;
	unsigned int dim, rows, cols;
	// bool is_complex;

	m_type** mat_arr;
} Matrix;

// MATRIX DE/INIT OPERATIONS
Matrix* m_build(const char* title, unsigned int n_rows, unsigned int n_cols);
Matrix* m_build_file(const char* filename);
void m_print(Matrix* mat);
void m_destroy(Matrix* mat);

// MATRIX ARITHMETIC OPERATIONS
Matrix* m_add(Matrix* mat1, Matrix* mat2);
Matrix* m_scal_mult(Matrix* mat, int num);
Vector* m_vec_mult(Matrix* mat, Vector* vec);
Matrix* m_mat_mult(Matrix* mat1, Matrix* mat2);

// MATRIX OPERATIONS
Matrix* m_rref(Matrix* mat); // return row reduced form of a matrix
Matrix* m_inv(Matrix* mat);  // return inverse of a matrix
Matrix* m_adj(Matrix* mat);  // return adjoint of a matrix (transpose)
Matrix* m_rot(Matrix* mat);  // return a rotated matrix by 90 deg clockwise
int m_det(Matrix* mat);      // return determinant of a square matrix
int m_tr(Matrix* mat);       // return trace of a matrix
//int m_dot(Matrix* mat);      // return dot product of a matrix

// MATRIX UTILITY FUNCTIONS
// - RREF UTILITIES
void m_row_swap(Matrix* mat, unsigned int row1, unsigned int row2);
void m_row_add(Matrix* mat, unsigned int row_src, unsigned int row_dest, m_type num);
void m_row_scale(Matrix* mat, unsigned int row, m_type num);

// - ROT UTILITIES
void m_row_rev(int* row, int row_size);

#endif

/* END FILE */