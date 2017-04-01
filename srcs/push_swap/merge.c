/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:52:52 by jye               #+#    #+#             */
/*   Updated: 2017/01/03 17:33:03 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ft_printf.h>

static int	is_sorted(t_stack *high_node)
{
	t_stack *low_node;

	low_node = high_node->next;
	while (low_node)
	{
		if (high_node->var > low_node->var)
			return (1);
		high_node = low_node;
		low_node = low_node->next;
	}
	return (0);
}

static void	mini_sort(t_stack *node)
{
	int a;
	int b;
	int c;

	a = node->var;
	b = node->next->var;
	c = node->next->next->var;
	if (a > b && b < c && c < a)
		ft_printf("ra\n");
	if (a > b && b > c && c < a)
		ft_printf("ra\nsa\n");
	if (a < b && b > c && c > a)
		ft_printf("ra\nsa\nrra\n");
	if (a < b && b > c && c < a)
		ft_printf("rra\n");
	if (a > b && b < c && c > a)
		ft_printf("sa\n");
}

t_stack		*merge(t_stack *dst, t_stack *to_merge, char c, char lock__)
{
	t_stack *d;

	if (!lock__)
		d = merge_lock(dst, to_merge, c);
	else
		d = merge_unlock(dst, to_merge, c);
	return (d);
}

t_stack		*merge_sort(t_stack **stack, int stack_size, char c, char lock__)
{
	t_stack	*a;
	t_stack *b;
	t_stack	*merged;

	b = NULL;
	a = NULL;
	if (stack_size == 2)
		return (merge2(stack, c));
	else if (stack_size == 3)
		return (merge3(stack, c, lock__));
	b = merge_sort(stack, stack_size / 2, 'b', 	\
					lock__ && c == 'b' ? 1 : 0);
	a = merge_sort(stack, stack_size % 2 ? 								\
					(stack_size / 2 + 1) : stack_size / 2, 'a', 		\
					lock__ && c == 'a' ? 1 : 0);
	if (c == 'b')
		merged = merge(b, a, c, lock__ && c == 'b' ? 1 : 0);
	else
		merged = merge(a, b, c, lock__ && c == 'a' ? 1 : 0);
	return (merged);
}

void		push_swap(t_stack **stack, int stack_size)
{
	t_stack	*a;
	t_stack *b;
	t_stack	*c;

	if (!is_sorted(*stack))
		return ;
	c = NULL;
	if (stack_size == 1)
		return ;
	else if (stack_size == 2)
		c = merge_sort(stack, stack_size, 'a', 1);
	else if (stack_size == 3)
		mini_sort(*stack);
	else
	{
		b = merge_sort(stack, stack_size / 2, 'b', 1);
		a = merge_sort(stack, stack_size % 2 ? 							\
						(stack_size / 2 + 1) : stack_size / 2, 'a', 1);
		c = merge(a, b, 'a', 1);
		set_head(c, stack_size);
	}
	while (*stack)
		pop_stack__(stack);
	while (c)
		pop_stack__(&c);
}
