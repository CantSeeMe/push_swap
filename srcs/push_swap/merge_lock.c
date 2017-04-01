/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_lock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 20:02:40 by jye               #+#    #+#             */
/*   Updated: 2017/01/02 20:50:25 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ft_printf.h>

static void	push_stack(t_stack **dst, int var, char c)
{
	ft_printf("p%c\n", c);
	push_stack__(dst, var);
}

static void	go_to_last(t_stack *dst, char c)
{
	t_stack *tmp;

	tmp = dst;
	while (tmp)
	{
		tmp = tmp->next;
		ft_printf("r%c\n", c);
	}
}

static void	norm2__(t_stack **dst, t_stack *p_dst, char c, int *bool__)
{
	if (!*bool__ && (*bool__ = 1))
		while (*dst != p_dst)
		{
			ft_printf("r%c\n", c);
			su_stack__(dst);
		}
	else
		while (*dst != p_dst)
		{
			ft_printf("rr%c\n", c);
			sd_stack__(dst);
		}
}

static void	norm1__(t_stack **dst, int var, char c, int *bool__)
{
	t_stack *p_dst;

	p_dst = chk_order_var(*dst, var, c == 'a' ? 0 : 1);
	if (p_dst == *dst)
		push_stack(dst, var, c);
	else if (p_dst == NULL)
	{
		if (!*bool__ && (*bool__ = 1))
			go_to_last(*dst, c);
		push_stack(dst, var, c);
	}
	else
	{
		norm2__(dst, p_dst, c, bool__);
		push_stack(dst, var, c);
	}
}

t_stack		*merge_lock(t_stack *dst, t_stack *to_merge, char c)
{
	t_stack	*p_dst;
	int		bool__;
	int		var;

	bool__ = 0;
	while (to_merge)
	{
		var = to_merge->var;
		pop_stack__(&to_merge);
		norm1__(&dst, var, c, &bool__);
	}
	p_dst = get_s_head(dst, c == 'a' ? 0 : 1);
	while (p_dst != dst)
	{
		ft_printf("rr%c\n", c);
		sd_stack__(&dst);
	}
	return (dst);
}
