/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:46:06 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/16 10:12:50 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

t_node	*fill_list(int size, int *val_array)
{
	int		i;
	t_node	*head;
	t_node	*new_node;
	t_node	*temp;

	i = 1;
	head = (t_node *)malloc(sizeof(t_node));
	head->val = val_array[0];
	head->next = NULL;
	temp = head;
	while (i < size)
	{
		new_node = malloc(sizeof(t_node));
		new_node->val = val_array[i];
		new_node->next = NULL;
		temp->next = new_node;
		temp = new_node;
		i++;
	}
	return (head);
}

void	print_list(t_node *head)
{
	t_node	*node;

	node = head;
	while (node)
	{
		ft_printf("Value:%i\n", node->val);
		node = node->next;
	}
}

void	free_stack(struct t_node *head)
{
	t_node	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int	get_stack_len(t_node *stack_head)
{
	int	len;

	len = 0;
	while (stack_head)
	{
		stack_head = stack_head->next;
		len++;
	}
	return (len);
}

int	*stack_get_array(t_node	*stack_head)
{
	int		*array;
	int		i;
	size_t	len;

	i = 0;
	len = get_stack_len(stack_head);
	array = malloc(len * sizeof(int));
	if (!array)
		return (NULL);
	while (stack_head)
	{
		array[i] = stack_head->val;
		i++;
		stack_head = stack_head->next;
	}
	return (array);
}
