#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "matrix.h"


struct matrixf create_zeros_matrix(int size_row, int size_col)
{
	struct matrixf res;
	res.this_ = &res;

	res.rows = size_row;
	res.cols = size_col;

	for (int r = 0; r < C_MATRIX_MAX_NUM; ++r)
	{
		memset(res.items[r], 0, sizeof(float) * C_MATRIX_MAX_NUM);
	}


	res.add = add_matrix;
	res.diff = diff_matrix;
	res.mult = mult_matrix;
	res.mult_const = mult_const_matrix;

	res.inverse = inverse_matrix;
	res.determinant = determinant_matrix;
	res.transpose = transpose_matrix;

	return res;
}

struct matrixf add_matrix(struct matrixf* A, struct matrixf* B)
{
	struct matrixf res = *A;

	if ((A->rows != B->rows) || (A->cols != B->cols))
	{
		assert((A->rows != B->rows) || (A->cols != B->cols));
	}

	for (int r = 0; r < A->rows; ++r)
	{
		for (int c = 0; c < A->cols; ++c)
		{
			res.items[r][c] += B->items[r][c];
		}
	}

	return res;
}

struct matrixf diff_matrix(struct matrixf* A, struct matrixf* B)
{
	struct matrixf res = *A;

	if ((A->rows != B->rows) || (A->cols != B->cols))
	{
		assert((A->rows != B->rows) || (A->cols != B->cols));
	}

	for (int r = 0; r < A->rows; ++r)
	{
		for (int c = 0; c < A->cols; ++c)
		{
			res.items[r][c] -= B->items[r][c];
		}
	}

	return res;
}