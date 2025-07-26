/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 21:28:08 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/17 00:56:16 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <unistd.h>

static t_node	*push(t_node **from, t_node **to)
{
	t_node	*temp;

	if (*from == NULL)
		return (NULL);
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
	return ((*from));
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_node **stack_b, t_node **stack_a)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
