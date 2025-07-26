/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacedo- <mmacedo-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-06-18 14:42:37 by mmacedo-          #+#    #+#             */
/*   Updated: 2025-06-18 14:42:37 by mmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct t_node
{
	int					val;
	struct t_node		*next;

}t_node;

t_node	*fill_list(int size, int *val_array);
void	print_list(t_node *head);
void	free_stack(t_node *head);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_b, t_node **stack_a);
void	rrr(t_node **stack_a, t_node **stack_b);
void	quicksort_array(int arr[], int low, int high);
void	small_sort(t_node **stack_a, t_node **stack_b, int len);
void	sort(t_node **stack_a_head, t_node **stack_b_head, int len);
void	three_number_sort(t_node **stack_a, int x, int y, int z);
void	push_all_to_a(t_node **stack_b_head, t_node **stack_a_head);
void	small_sort_b_and_push(t_node **stack_b, t_node **stack_a, int len);
void	get_min_max(t_node *stack, int *min_val, int *max_val);
void	normalize_stack(t_node *stack, int size);
void	chunk_sort(t_node **stack_a, t_node **stack_b, int size);
void	free_tab(char **tab);
int		*parse(char **argv);
int		*stack_get_array(t_node	*stack_head);
int		count_argv(char **arg);
int		count_arg(char *arg);
int		get_min_index(t_node *stack, int *min);
int		get_max_index(t_node *stack, int *max);
int		get_stack_len(t_node *stack_head);
int		is_sorted(t_node *array);
int		count_argv(char **argv);
int		get_max_bits(int size);
int		get_index(t_node *stack, int value);
int		has_dupes(int *array, int len);
int		ft_atoi_int_max(const char *str);
int		int_max(char **argv);

#endif