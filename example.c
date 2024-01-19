#include <stdio.h>
#include "quicksort.h"

#define ARRAY_SIZE 10


int double_compare(void* first, void* second)
{
	return (*((double*)first)) > (*((double*)second));
}


int main()
{
	double array[ARRAY_SIZE] = {0.9, 0.0, -3.4, 1.4, 0.0, 3.5, 1.2, -0.1, -1.0, 2.2};
	
	printf("Unsorted:\n");
	for(int i=0; i<ARRAY_SIZE; i++)
	{
		printf("%lf\n", array[i]);
	}

	quicksort(array, ARRAY_SIZE, sizeof(double), double_compare);
	
	printf("Sorted:\n");
	for(int i=0; i<ARRAY_SIZE; i++)
	{
		printf("%lf\n", array[i]);
	}

	return 0;
}

