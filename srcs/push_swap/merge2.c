/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:45:39 by jye               #+#    #+#             */
/*   Updated: 2017/01/03 16:50:35 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ft_printf.h>

t_stack	*merge2(t_stack **stack, char c)
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
	push_stack__(&b, (*stack)->var);
	pop_stack__(stack);
	push_stack__(&b, (*stack)->var);
	pop_stack__(stack);
	if (c == 'b')
		ft_printf("pb\npb\n");
	else
		swap_elem__(b);
	return (b);
}
