/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 21:32:31 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/17 00:57:26 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include <unistd.h>

static t_node	*rotate(t_node **head, int k)
{
	int		i;
	t_node	*current;

	if (head == NULL || k == 0)
		return (*head);
	i = 0;
	while (i < k)
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = *head;
		current = current->next;
		*head = (*head)->next;
		current->next = NULL;
		i++;
	}
	return (*head);
}

void	ra(t_node **stack_a)
{
	rotate(stack_a, 1);
	ft_printf("ra\n");
}

void	rb(t_node **stack_b)
{
	rotate(stack_b, 1);
	ft_printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a, 1);
	rotate(stack_b, 1);
	ft_printf("rr\n");
}
