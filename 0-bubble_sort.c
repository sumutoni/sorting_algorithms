#include "sort.h"

/**
 * check_sorted - checks if array is sorted
 * @array: array of integers
 * @size: number of elements
 *
 * Return: 1 for sorted, 0 for not sorted
 */
int check_sorted(int *array, size_t size)
{
	int sorted = 1, i;

	for (i = 0; i < (size - 1); i++)
	{
		if (array[i] > array[i + 1])
		{
			sorted = 0;
			return (sorted);
		}
	}
	return (sorted);
}
/**
 * bubble_sort - function to sort integers in ascending order using bubble
 * sort algorithm
 * @array: array of integers
 * @size: number of elements
 */
void bubble_sort(int *array, size_t size)
{
	int temp, i;

	while (!check_sorted(array, size))
	{
		for (i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
