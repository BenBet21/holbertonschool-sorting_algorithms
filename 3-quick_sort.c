#include <stdio.h>
#include <stdlib.h>

/**
 * swap - Swaps two elements in an array
 * @array: The array
 * @i: The index of the first element
 * @j: The index of the second element
 */
void swap(int *array, int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
    print_array(array, 10);
}

/**
 * partition - Partitions the array around a pivot
 * @array: The array to be partitioned
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 * Return: The index of the pivot
 */
int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(array, i, j);
        }
    }

    swap(array, i + 1, high);
    return (i + 1);
}

/**
 * quick_sort_recursive - Recursive helper function for quick_sort
 * @array: The array to be sorted
 * @low: The lower index of the partition
 * @high: The higher index of the partition
 */
void quick_sort_recursive(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(array, low, high);
        quick_sort_recursive(array, low, pivot_index - 1);
        quick_sort_recursive(array, pivot_index + 1, high);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1);
}

/**
 * print_array - Prints the elements of an array
 * @array: The array to be printed
 * @size: The size of the array
 */
void print_array(int *array, size_t size)
{
    printf("[");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");
}

int main()
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    quick_sort(array, 10);
    print_array(array, 10);
    return 0;
}
