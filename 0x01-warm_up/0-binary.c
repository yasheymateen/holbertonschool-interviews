#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - prints an array of integers
 * @array: a pointer to the 1st element in the array
 * @size: number of elements in the array
 */
void print_array(int *array, size_t size)
{
	size_t i;

	if (!array)
		return;
	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i != size - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_search - searches for a value in a sorted array of integers using
 * binary search. Also prints the new array every time the array is split.
 * @array: a pointer to the first element of the array to search in
 * @size:  the number of elements in array
 * @value: the value to search for
 *
 * Return: index where value is located. If the value is not present
 * or the array is NULL, return -1.
 */
int binary_search(int *array, size_t size, int value)
{
	int left, right, mid;

	if (!array)
		return (-1);
	left = 0, right = size - 1;
	while (left <= right)
	{
		print_array(array + left, right - left + 1);
		mid = (left + right) / 2;

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}
