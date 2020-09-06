#ifndef __MATRIX_H__
#define __MATRIX_H__

#define C_MATRIX_MAX_NUM (16U)

struct matrixf 
{
	struct matrixf* this_;

	float items[C_MATRIX_MAX_NUM][C_MATRIX_MAX_NUM];
	int rows, cols;

	struct matrixf(*add)(struct matrixf* this_, struct matrixf* src);
	struct matrixf(*diff)(struct matrixf* this_, struct matrixf* src);
	struct matrixf(*mult)(struct matrixf* this_, struct matrixf* src);
	struct matrixf(*mult_const)(struct matrixf* this_, float m);

	struct matrixf(*inverse)(struct matrixf* this_);
	struct matrixf(*determinant)(struct matrixf* this_);
	struct matrixf(*transpose)(struct matrixf* this_);
};


extern struct matrixf create_zeros_matrix(int size_row, int size_col);

static struct matrixf add_matrix(struct matrixf* A, struct matrixf* B);
static struct matrixf diff_matrix(struct matrixf* A, struct matrixf* B);
static struct matrixf mult_matrix(struct matrixf* A, struct matrixf* B);
static struct matrixf mult_const_matrix(struct matrixf* A, float m);
static struct matrixf inverse_matrix(struct matrixf* A);
static struct matrixf determinant_matrix(struct matrixf* A);
static struct matrixf transpose_matrix(struct matrixf* A);

#endif //__MATRIX_H__