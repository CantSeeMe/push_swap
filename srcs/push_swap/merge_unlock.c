/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kek.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 17:58:21 by jye               #+#    #+#             */
/*   Updated: 2017/01/02 21:24:00 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ft_printf.h>

static void	push_stack(t_stack **dst, int var, char c)
{
	push_stack__(dst, var);
	ft_printf("p%c\n", c);
}

static void	norm1__(t_stack **dst, int n, char c)
{
	if (n < 0)
		while (n)
		{
			ft_printf("rr%c\n", c);
			sd_stack__(dst);
			++n;
		}
	else
		while (n)
		{
			ft_printf("r%c\n", c);
			su_stack__(dst);
			--n;
		}
}

static void	norm2__(t_stack **dst, int var, int n, char c)
{
	norm1__(dst, n, c);
	push_stack(dst, var, c);
}

t_stack		*merge_unlock(t_stack *dst, t_stack *to_merge, char c)
{
	t_stack	*p_dst;
	int		var;
	int		n;
	int		sstack;

	sstack = sizeof_stack(dst);
	while (to_merge)
	{
		var = to_merge->var;
		pop_stack__(&to_merge);
		p_dst = chk_order_var(dst, var, c == 'a' ? 0 : 1);
		if ((n = get_opt_ins(dst, sstack, p_dst)) < 0)
			norm2__(&dst, var, n, c);
		else if (n == sstack)
			push_stack(&dst, var, c);
		else
			norm2__(&dst, var, n, c);
		++sstack;
	}
	return (dst);
}
