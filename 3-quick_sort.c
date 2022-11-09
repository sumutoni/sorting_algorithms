#include "sort.h"

/**
 * partition - partition array using lomuto scheme
 * @array: array of integers
 * @low: start
 * @high: end
 *
 * Return: pivot position
 */
size_t partition(int *array, size_t low, size_t high)
{
	size_t i = -1, j;
	int temp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= array[high])
		{
			i++;
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
	}
	temp = array[high];
	array[low] = array[i + 1];
	array[i + 1] = temp;
	return (i + 1);
}
/**
 * quick sort - function to sort integers using quick sort algorithm
 * @array: array of integers
 * @size: number of elements
 */
void quick_sort(int *array, size_t size)
{
	size_t piv;
	while (!check_sorted(array, size))
	{
		piv = partition(array, 0, size - 1);
		piv = partition(array, 0, piv);
		piv = partition(array, piv, size - 1);
	}
}
