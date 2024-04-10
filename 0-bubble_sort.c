#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers
 * in ascending order using Bubble sort algorithm
 * @array: The array of integers to be sorted
 * @size: The size of the array
 *
 * Description: This function sorts the @array using the Bubble sort algorithm.
 * It compares adjacent elements of the array and swaps them if necessary to
 * arrange them in ascending order.
 */

void bubble_sort(int *array, size_t size)
{
	size_t index, index_echange, tempo;

	for (index = 0; index < size - 1; index++)
	{
		for (index_echange = 0; index_echange < (size - 1); index_echange++)
		{
			if (array[index_echange] > array[index_echange + 1])
			{
				tempo = array[index_echange];
				array[index_echange] = array[index_echange + 1];
				array[index_echange + 1] = tempo;

				print_array(array, size);
			}
		}
	}
}
