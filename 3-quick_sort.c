#include "sort.h"

/**
 * quick_sort - function to sort an array of integers
 *              in ascending order using the Quick sort algorithm
 * @array: array
 * @size: array's size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_s(array, 0, size - 1, size);
}

/**
 * partition - partition
 * @array: array
 * @lower: lower
 * @higher: higher
 * @size: array's size
 * Return: i
 */
int partition(int *array, int lower, int higher, size_t size)
{
	int i = lower - 1, j = lower;
	int pivot = array[higher], aux = 0;

	for (; j < higher; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[higher])
	{
		aux = array[i + 1];
		array[i + 1] = array[higher];
		array[higher] = aux;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_s - quick sort
 * @array: given array
 * @lower: lower
 * @higher:highergher
 * @size: array's size
 * Return: void
 */
void quick_s(int *array, int lower, int higher, size_t size)
{
	int pivot;

	if (lower < higher)
	{
		pivot = partition(array, lower, higher, size);
		quick_s(array, lower, pivot - 1, size);
		quick_s(array, pivot + 1, higher, size);
	}
}

