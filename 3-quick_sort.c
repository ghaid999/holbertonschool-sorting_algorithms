#include "sort.h"

/**
 * swap_items - Swaps two integers in an array.
 * @array: The array containing the elements.
 * @size: The size of the array (for printing).
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap_items(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Partitions the array using the Lomuto scheme.
 * @array: The array to partition.
 * @size: The total size of the array.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition (pivot).
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap_items(array, size, &array[i], &array[j]);
			i++;
		}
	}
	swap_items(array, size, &array[i], &array[high]);
	return (i);
}

/**
 * quick_recursion - Helper function to handle recursive calls.
 * @array: The array to sort.
 * @size: The total size of the array.
 * @low: Starting index.
 * @high: Ending index.
 */
void quick_recursion(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int p_idx = lomuto_partition(array, size, low, high);

		quick_recursion(array, size, low, p_idx - 1);
		quick_recursion(array, size, p_idx + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers using Quick Sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_recursion(array, size, 0, (int)size - 1);
}
