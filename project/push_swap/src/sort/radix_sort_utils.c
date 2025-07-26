/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 20:27:36 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/17 01:24:21 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((1 << bits) < size)
		bits++;
	return (bits);
}

/*Update min_val and max_val to reflect the minimum and maximum values
**found in the given stack*/
void	get_min_max(t_node *stack, int *min_val, int *max_val)
{
	*min_val = stack->val;
	*max_val = stack->val;
	while (stack)
	{
		if (stack->val < *min_val)
			*min_val = stack->val;
		if (stack->val > *max_val)
			*max_val = stack->val;
		stack = stack->next;
	}
}

/*Convert the stack to an int array, then
**sorts it using quicksort.
**normalize the stack: the value becomes the index*/
void	normalize_stack(t_node *stack, int size)
{
	int		*array;
	int		i;
	t_node	*current;

	array = stack_get_array(stack);
	quicksort_array(array, 0, size - 1);
	current = stack;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (array[i] == current->val)
			{
				current->val = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	free(array);
}
