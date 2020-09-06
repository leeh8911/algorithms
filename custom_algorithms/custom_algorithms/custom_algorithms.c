#include "custom_algorithms.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void static_test_vector(void);

void main(void)
{
	printf("1. test vector functions\n");
	printf("****1.1. static test******************************************\n");
	static_test_vector();
}

void static_test_vector(void)
{
	printf("start test : vector\n");

	float arA[] = { 1.f, 2.f, 3.f };
	float arB[] = { 4.f, -2.f, 3.f };

	printf("test create\n");
	struct vectorf A = create_vector(arA, 3);
	struct vectorf B = create_vector(arB, 3);
	PRINT_VECTOR(A);
	PRINT_VECTOR(B);


	printf("test calculate\n");
	struct vectorf addAB = A.add(&A, &B);
	PRINT_VECTOR(addAB);

	struct vectorf diffAB = A.diff(&A, &B);
	PRINT_VECTOR(diffAB);

	struct vectorf multAB = A.mult_const(&A, 3.f);
	PRINT_VECTOR(multAB);

	float dotAB = A.dot(&A, &B);
	printf("dotAB : %2.2f\n", dotAB);

	struct vectorf crossAB= A.cross(&A, &B);
	PRINT_VECTOR(crossAB);

	printf("end test : vector\n");
}