#include "sort.h"

/**
* bubble_sort - Sorts an array of integers in ascending order
*               using the Bubble sort algorithm
* @array: Pointer to the array of integers to sort
* @size: Number of elements in the array
*
* Description: After each swap of two elements, the entire array
* is printed. The algorithm runs in O(n^2) average and worst case,
* and O(n) best case (already sorted).
*/
void bubble_sort(int *array, size_t size)
{
size_t i;
int swapped, temp;

if (array == NULL || size < 2)
return;

swapped = 1;
while (swapped)
{
swapped = 0;
for (i = 0; i < size - 1; i++)
{
if (array[i] > array[i + 1])
{
temp = array[i];
array[i] = array[i + 1];
array[i + 1] = temp;
print_array(array, size);
swapped = 1;
}
}
size--;
}
}
