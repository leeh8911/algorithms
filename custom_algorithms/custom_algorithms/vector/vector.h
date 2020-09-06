#ifndef __VECTOR_H__
#define __VECTOR_H__

#define C_VECTOR_MAX_NUM (256U)

#define PRINT_VECTOR(src) \
do{\
printf("%s : ", #src);\
print_vector(&src);\
} while (0)

#define ADD_VECTOR(des, src) des.add(des.this_, &src) 

struct vectorf
{
	struct vectorf* this_;
	float items[C_VECTOR_MAX_NUM];
	int elements_number;

	struct vectorf(*add)(struct vectorf* this_, struct vectorf* src);
	struct vectorf(*diff)(struct vectorf* this_, struct vectorf* src);
	struct vectorf(*mult_const)(struct vectorf* this_, float src);
	float (*dot)(struct vectorf* this_, struct vectorf* src);
	struct vectorf(*cross)(struct vectorf* this_, struct vectorf* src);

	void (*print)(struct vectorf* this_);
};

extern struct vectorf create_vector(float* src, int num);
extern void print_vector(struct vectorf* this_);

static struct vectorf add_vector(struct vectorf* this_, struct vectorf* src);
static struct vectorf diff_vector(struct vectorf* this_, struct vectorf* src);
static struct vectorf mult_const_vector(struct vectorf* this_, float m);
static float  dot_vector(struct vectorf* this_, struct vectorf* src);
static struct vectorf cross_vector(struct vectorf* this_, struct vectorf* src);


#endif //__VECTOR_H__