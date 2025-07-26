/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:53:47 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/17 01:28:52 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/*Partition function used in quicksort.
**It chooses the last element as the pivot and rearranges
**the elements in the array such that all elements less than or equal
**to the pivot are on the left of it, and all greater elements on the right.
**Returns the final index position of the pivot.*/
static int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/*Recursive quicksort function to sort an array in ascending order.
**It partitions the array and then recursively sorts the two partitions.*/
void	quicksort_array(int arr[], int low, int high)
{
	int	i;

	if (low < high)
	{
		i = partition(arr, low, high);
		quicksort_array(arr, low, i - 1);
		quicksort_array(arr, i + 1, high);
	}
}

/*Computes the median value of the first n elements in a stack.
**First converts the stack to an array.
**then sorts the array using quicksort.
**Returns the middle element (or the lower middle for even n).
**Returns 0 if conversion fails.*/
int	get_median(t_node *stack, int n)
{
	int	*array;
	int	median;

	array = stack_get_array(stack);
	quicksort_array(array, 0, n - 1);
	if (!array)
		return (0);
	if (n % 2 == 0)
	{
		median = array[n / 2 - 1];
	}
	else
	{
		median = array[n / 2];
	}
	free(array);
	return (median);
}
