#include "sort.h"
#include <stdio.h>

/**
 * partitionss - find partition for quicksort used Lomuto scheme
 * @array: array
 * @lo: lowest index of the partition
 * @hi: highest index of the partition
 * @size: size of array (imput)
 * Return: Partitionn Index
 */
size_t partitionss(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t i, j;
	int swap, pivot;

	pivot = array[hi];
	i = lo - 1;
	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, size);
			}
		}
	}
	if (array[hi] < array[i + 1])
	{
		swap = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = swap;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort1 - sorts a partition of an array of integers
 * @array: array to sort
 * @lo: lowerst index of the partition
 * @hi: highest index of the partition
 * @size: size of the array
 * Return: VOID
 */
void quicksort1(int *array, ssize_t lo, ssize_t hi, size_t size)
{
	ssize_t pivot;

	if (lo < hi)
	{
		pivot = partitionss(array, lo, hi, size);
		quicksort1(array, lo, pivot - 1, size);
		quicksort1(array, pivot + 1, hi, size);

	}
}

/**
 * quick_sort - sorts an array of ints
 * @array: Array
 * @size: Size of array
 * Return: VOID
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort1(array, 0, size - 1, size);
}
