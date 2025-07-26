/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:18:51 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/17 00:42:44 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**Radix sort here uses binary representation of the numbers.
**Because we have two stacks, 0 goes to stack_b, 1 stays in stack_a
**It normalize the stack so values are in the range eg:
**stack_a = [3, 8, 2, 9], noralized = [0, 1, 2, 3].
**Determine the number of bits needed to represent 
**the largest number size - 1 since it's normalized.
**For each bit position:
**	- Iterate over all elements in stack_a.
**	- If the current bit (i-th bit) of the element's 
**	value is 0, push it to stack_b.
** 	- Otherwise, rotate stack_a to move the element to the bottom.
**After processing all elements for the current bit, 
**push all elements from stack_b back to stack_a.
**Repeat for the next bit until all bits are processed*/
void	radix_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int	i;
	int	j;
	int	max_bits;
	int	stack_size;

	normalize_stack(*stack_a, size);
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		stack_size = get_stack_len(*stack_a);
		j = 0;
		while (j < stack_size)
		{
			if ((((*stack_a)->val >> i) & 1) == 0)
				pb(stack_b, stack_a);
			else
				ra(stack_a);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}

void	sort(t_node **stack_a, t_node **stack_b, int size)
{
	if (is_sorted(*stack_a))
		return ;
	if (size <= 5)
		small_sort(stack_a, stack_b, size);
	else if (size <= 100)
		chunk_sort(stack_a, stack_b, size);
	else
		radix_sort(stack_a, stack_b, size);
}
