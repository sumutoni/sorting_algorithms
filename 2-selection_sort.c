#include "sort.h"

/**
 * selection sort - function to sort integers using selection
 * algorithm
 * @array: array of integers
 * @size: number of elements
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, idx;
	int temp;

	for (i = 0; i < (size - 1); i++)
	{
		temp = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (temp > array[j])
			{
				temp = array[j];
				idx = j;
			}
		}
		if (temp < array[i])
		{
			array[idx] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
