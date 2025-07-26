/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 21:36:38 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/17 00:56:27 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"

static t_node	*reverse_rotate(t_node **head)
{
	t_node	*last;
	t_node	*previous;

	if (head == NULL)
		return (*head);
	last = *head;
	while (last->next)
	{
		previous = last;
		last = last->next;
	}
	previous->next = NULL;
	last->next = *head;
	*head = last;
	return (*head);
}

void	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
