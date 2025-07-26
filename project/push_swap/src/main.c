/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 00:39:36 by mmacedo-          #+#    #+#             */
/*   Updated: 2025/06/17 01:09:38 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_node	*stack_a_head;
	t_node	*stack_b_head;
	int		*arg_array;
	int		len;

	len = count_argv(argv);
	if (argc < 2 || len == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	arg_array = parse(argv);
	if (!arg_array || has_dupes(arg_array, len))
	{
		ft_printf("Error\n");
		return (0);
	}
	stack_b_head = NULL;
	stack_a_head = fill_list(len, arg_array);
	sort(&stack_a_head, &stack_b_head, len);
	free_stack(stack_a_head);
	free_stack(stack_b_head);
	free(arg_array);
	return (0);
}
