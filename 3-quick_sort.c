#include "sort.h"

/**
* lomuto_partition - Partitions the array using Lomuto scheme
* @array: The array to partition
* @low: Starting index
* @high: Ending index (pivot position)
* @size: Size of the array
*
* Return: Final index of the pivot
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot, i, j, temp;

pivot = array[high];
i = low - 1;

for (j = low; j < high; j++)
{
if (array[j] < pivot)
{
i++;
if (i != j)
{
temp = array[i];
array[i] = array[j];
array[j] = temp;
print_array(array, size);
}
}
}

if (array[i + 1] != array[high])
{
temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
print_array(array, size);
}

return (i + 1);
}

/**
* quick_sort_recursive - Recursively sorts partitions
* @array: The array to sort
* @low: Starting index
* @high: Ending index
* @size: Size of the array
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
int pivot;

if (low < high)
{
pivot = lomuto_partition(array, low, high, size);
quick_sort_recursive(array, low, pivot - 1, size);
quick_sort_recursive(array, pivot + 1, high, size);
}
}

/**
* quick_sort - Sorts an array of integers in ascending order
*              using the Quick sort algorithm (Lomuto partition)
* @array: Pointer to the array to sort
* @size: Number of elements in the array
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_recursive(array, 0, size - 1, size);
}
