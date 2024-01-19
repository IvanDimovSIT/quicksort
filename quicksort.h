#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stddef.h>

void quicksort(void* array, size_t count, size_t element_size, int (*compare)(void* first, void* second));

#endif

