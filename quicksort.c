#include "quicksort.h"
#include <stdlib.h>
#include <string.h>


void* find_pivot(void** array_ptr, size_t count, int (*compare)(void* first, void* second))
{
	void* const start = array_ptr[0];
	void* const middle = array_ptr[count/2];
	void* const end = array_ptr[count-1];

	if((compare(start, middle) && compare(end, start)) || (compare(start, end) && compare(middle, start)))
	{
		return start;
	}
	else if((compare(middle, start) && compare(end, middle)) || (compare(middle, end) && compare(start, middle)))
	{
		return middle;
	}
	else
	{
		return end;
	}
}


void quicksort_ptr(void** array_ptr, size_t count, int (*compare)(void* first, void* second))
{
	if(count <= 1)
	{
		return;
	}
	
	void* const pivot = find_pivot(array_ptr, count, compare);
	
	void** left = malloc(sizeof(void*)*(count-1));
	size_t left_count = 0;
	
	void** right = malloc(sizeof(void*)*(count-1));
	size_t right_count = 0;
	
	
	for(size_t i=0; i<count; i++)
	{
		if(array_ptr[i] == pivot)
		{
			continue;
		}
			
		if(compare(array_ptr[i], pivot))
		{
			right[right_count++] = array_ptr[i];
		}
		else
		{
			left[left_count++] = array_ptr[i];
		}
	}
	
	quicksort_ptr(left, left_count, compare);
	quicksort_ptr(right, right_count, compare);
	
	memcpy(array_ptr, left, sizeof(void*)*left_count);
	array_ptr[left_count] = pivot;
	memcpy(array_ptr+left_count+1, right, sizeof(void*)*right_count);
	
	free(left);
	free(right);
}


void quicksort(void* array, size_t count, size_t element_size, int (*compare)(void* first, void* second))
{
	if(count <= 1)
	{
		return;
	}
	
	void** array_ptr = malloc(sizeof(void*)*count);
	for(size_t i=0; i<count; i++)
	{
		array_ptr[i] = array+i*element_size;
	}
	
	quicksort_ptr(array_ptr, count, compare);
	
	void* temp_array = malloc(element_size*count);
	for(size_t i=0; i<count; i++)
	{
		memcpy(temp_array+i*element_size, array_ptr[i], element_size);
	}
	
	memcpy(array, temp_array, element_size*count);
	
	free(array_ptr);
	free(temp_array);
}

