/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:01:59 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/17 01:22:20 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_number_sort(t_node **stack_a, int x, int y, int z)
{
	if (is_sorted(*stack_a))
		return ;
	if ((*stack_a)->val < z && z < y)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (y < x && x < z)
		sa(stack_a);
	else if (y < z && z < x)
		ra(stack_a);
	else if (z < x && x < y)
		rra(stack_a);
	else if (z < y && y < x)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	five_number_sort(t_node **stack_a, t_node **stack_b)
{
	int	min_index;
	int	min;
	int	i;

	i = 0;
	min = 0;
	while (i < 2)
	{
		min_index = get_min_index(*stack_a, &min);
		while ((*stack_a)->val != min)
		{
			if (min_index <= get_stack_len(*stack_a) / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_b, stack_a);
		i++;
	}
	small_sort(stack_a, stack_b, 3);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	if ((*stack_a)->val > (*stack_a)->next->val)
		sa(stack_a);
}

void	fourth_number_sort(t_node **stack_a, t_node **stack_b)
{
	int	min_index;
	int	min;

	min = 0;
	min_index = get_min_index(*stack_a, &min);
	while ((*stack_a)->val != min)
	{
		if (min_index <= get_stack_len(*stack_a) / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_b, stack_a);
	small_sort(stack_a, stack_b, 3);
	pa(stack_a, stack_b);
}

void	small_sort(t_node **stack_a, t_node **stack_b, int len)
{
	if (len == 5)
		five_number_sort(stack_a, stack_b);
	if (len == 4)
		fourth_number_sort(stack_a, stack_b);
	if (len == 3)
	{
		three_number_sort(stack_a, (*stack_a)->val,
			(*stack_a)->next->val, (*stack_a)->next->next->val);
	}
	else if (len == 2)
	{
		if ((*stack_a)->val > (*stack_a)->next->val)
			sa(stack_a);
	}
}
