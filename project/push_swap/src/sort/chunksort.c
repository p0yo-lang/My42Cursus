/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 21:21:50 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/16 21:56:12 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**Pushes elements from stack_a to stack_b -
**that is within the range (min_val, max_val).
**For each element in stack_a, push in stack_b -
**if its value is in the chunk range,
**rotate stack_b if the pushed element is in the lower half of the chunk range,
**to keep smaller elements near the bottom.
**Elements outside the chunk range are rotated within stack_a to keep sorting.
*/
void	push_chunk_to_b(t_node **stack_a, t_node **stack_b, int min_val,
	int max_val)
{
	int	size;
	int	i;

	size = get_stack_len(*stack_a);
	i = 0;
	while (i < size)
	{
		if ((*stack_a)->val >= min_val && (*stack_a)->val < max_val)
		{
			pb(stack_b, stack_a);
			if ((*stack_b)->val < min_val + (max_val - min_val) / 2)
				rb(stack_b);
		}
		else
			ra(stack_a);
		i++;
	}
}

/*
Iterates over all chunks and pushes the corresponding
**elements from stack_a to stack_b using push_chunk_to_b.
**By dividing the value range (min_val, max_val) into chunks equal parts.
**For each chunk range, calls push_chunk_to_b to push elements.
*/
void	push_chunks(t_node **stack_a, t_node **stack_b, int chunks)
{
	int	i;
	int	chunk_min;
	int	chunk_max;
	int	min_val;
	int	max_val;

	min_val = 0;
	max_val = 0;
	i = 0;
	get_min_max(*stack_a, &min_val, &max_val);
	while (i < chunks && *stack_a)
	{
		chunk_min = min_val + (max_val - min_val) * i / chunks;
		chunk_max = min_val + (max_val - min_val) * (i + 1) / chunks;
		push_chunk_to_b(stack_a, stack_b, chunk_min, chunk_max);
		i++;
	}
}

/*
**Finds the maximum value in stack_b and its position.
**Rotates stack_b to bring the max value to the top with
**minimal rotations, then pushes it back to stack_a.
*/
void	push_max_to_a(t_node **stack_a, t_node **stack_b)
{
	int	max_val;
	int	max_pos;
	int	size;
	int	moves;

	max_pos = get_max_index(*stack_b, &max_val);
	size = get_stack_len(*stack_b);
	if (max_pos <= size / 2)
		moves = max_pos;
	else
		moves = size - max_pos;
	if (max_pos <= size / 2)
	{
		while (moves--)
			rb(stack_b);
	}
	else
	{
		while (moves--)
			rrb(stack_b);
	}
	pa(stack_a, stack_b);
}

/*
**Divides the stack values into chunks,
**pushes each chunk from stack_a to stack_b,
**then pushes all elements back to stack_a in sorted order.
*/
void	chunk_sort(t_node **stack_a, t_node **stack_b, int size)
{
	int	chunk_size;
	int	chunks;

	chunk_size = size / 5;
	chunks = (size + chunk_size - 1) / chunk_size;
	push_chunks(stack_a, stack_b, chunks);
	while (*stack_b)
		push_max_to_a(stack_a, stack_b);
}
