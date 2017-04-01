/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:10:35 by jye               #+#    #+#             */
/*   Updated: 2017/01/03 16:22:29 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ft_printf.h>

static t_stack	*merge_b(t_stack **stack, char c, char lock__)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if ((*stack)->var > (*stack)->next->var)
	{
		ft_printf("sa\n");
		swap_elem__(*stack);
	}
	ft_printf("pb\npb\n");
	push_stack__(&b, (*stack)->var);
	pop_stack__(stack);
	push_stack__(&b, (*stack)->var);
	pop_stack__(stack);
	push_stack__(&a, (*stack)->var);
	pop_stack__(stack);
	return (merge(b, a, c, lock__ && c == 'b' ? 1 : 0));
}

static t_stack	*merge_a(t_stack **stack, char c, char lock__)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	ft_printf("pb\n");
	push_stack__(&b, (*stack)->var);
	pop_stack__(stack);
	if ((*stack)->var > (*stack)->next->var)
	{
		ft_printf("sa\n");
		push_stack__(&a, (*stack)->var);
		pop_stack__(stack);
		push_stack__(&a, (*stack)->var);
		pop_stack__(stack);
	}
	else
	{
		push_stack__(&a, (*stack)->var);
		pop_stack__(stack);
		push_stack__(&a, (*stack)->var);
		pop_stack__(stack);
		swap_elem__(a);
	}
	return (merge(a, b, c, lock__ && c == 'a' ? 1 : 0));
}

t_stack			*merge3(t_stack **stack, char c, char lock__)
{
	t_stack *merged;

	if (c == 'a')
		merged = merge_a(stack, c, lock__);
	else
		merged = merge_b(stack, c, lock__);
	return (merged);
}
