#include "sort.h"

/**
 * selection_sort - sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @array: array pointer to an array.
 * @size: indicates the size of the array
 * Description: this function sorts an array of integers
 */

void selection_sort(int *array, size_t size)
{
	size_t index_ext, index_int, index_min;
	int tempo;

	if (array == NULL || size < 2)
		return;

	for (index_ext = 0; index_ext < size - 1; index_ext++)
	{
		index_min = index_ext;
		for (index_int = index_ext + 1; index_int < size; index_int++)
		{
			if (array[index_int] < array[index_min])
				index_min = index_int;
		}
		if (index_min != index_ext)
		{
			tempo = array[index_ext];
			array[index_ext] = array[index_min];
			array[index_min] = tempo;
			print_array(array, size);
		}
	}
}

