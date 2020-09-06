#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "vector.h"

void print_vector(struct vectorf* this_)
{
	char s[1000] = "";
	char temp[1000] = "";

	sprintf_s(s, 1000, "[");
	for (int i = 0; i < this_->elements_number-1; i++)
	{
		sprintf_s(temp, 1000, "%2.2f, ", this_->items[i]);
		strcat_s(s,1000, temp);
	}
	sprintf_s(temp, 1000, "%2.2f]\n", this_->items[this_->elements_number - 1]);
	strcat_s(s,1000, temp);

	printf("%s", s);
}

struct vectorf add_vector(struct vectorf* this_, struct vectorf* src)
{
	if (this_->elements_number != src->elements_number)
	{
		assert(this_->elements_number != src->elements_number);
	}
	struct vectorf res = *this_;
	for (int i = 0; i < res.elements_number; ++i)
	{
		res.items[i] += src->items[i];
	}

	return res;
}
struct vectorf diff_vector(struct vectorf* this_, struct vectorf* src)
{
	if (this_->elements_number != src->elements_number)
	{
		assert(this_->elements_number != src->elements_number);
	}
	struct vectorf res = *this_;
	for (int i = 0; i < res.elements_number; ++i)
	{
		res.items[i] -= src->items[i];
	}

	return res;
}
struct vectorf mult_const_vector(struct vectorf* this_, float m)
{
	struct vectorf res = *this_;
	for (int i = 0; i < res.elements_number; ++i)
	{
		res.items[i] *= m;
	}

	return res;
}
float  dot_vector(struct vectorf* this_, struct vectorf* src)
{
	if (this_->elements_number != src->elements_number)
	{
		assert(this_->elements_number != src->elements_number);
	}

	float res = 0.f;
	for (int i = 0; i < this_->elements_number; ++i)
	{
		res += this_->items[i] * src->items[i];
	}

	return res;
}
struct vectorf cross_vector(struct vectorf* this_, struct vectorf* src)
{
	if (this_->elements_number != src->elements_number)
	{
		assert(this_->elements_number != src->elements_number);
	}
	if((this_->elements_number != 3) || (this_->elements_number != 2))
	{
		assert((this_->elements_number != 3) || (this_->elements_number != 2));
	}

	struct vectorf res = *this_;
	res.elements_number = 3;
	res.items[0] = this_->items[1] * src->items[2] - this_->items[2] * src->items[1];
	res.items[1] = -1.f*(this_->items[0] * src->items[2] - this_->items[2] * src->items[0]);
	res.items[2] = this_->items[0] * src->items[1] - this_->items[1] * src->items[0];

	return res;
}

struct vectorf create_vector(float* src, int num)
{
	struct vectorf res;
	res.this_ = &res;

	memmove(res.items, src, sizeof(float) * num);
	res.elements_number = num;


	res.add = add_vector;
	res.diff = diff_vector;
	res.cross = cross_vector;
	res.dot = dot_vector;
	res.mult_const = mult_const_vector;
	res.print = print_vector;

	return res;
}