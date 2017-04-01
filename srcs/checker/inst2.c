/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 19:35:43 by jye               #+#    #+#             */
/*   Updated: 2016/12/30 20:09:03 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <utils.h>

void	ss(t_stack **a, t_stack **b, char debug__)
{
	if (*a && (*a)->next)
		swap_elem__(*a);
	if (*b && (*b)->next)
		swap_elem__(*b);
	if (debug__)
		print_stack(*a, *b, SS);
}

void	pa(t_stack **a, t_stack **b, char debug__)
{
	if (*b)
	{
		push_stack__(a, (*b)->var);
		pop_stack__(b);
	}
	if (debug__)
		print_stack(*a, *b, PA);
}

void	pb(t_stack **a, t_stack **b, char debug__)
{
	if (*a)
	{
		push_stack__(b, (*a)->var);
		pop_stack__(a);
	}
	if (debug__)
		print_stack(*a, *b, PB);
}

void	ra(t_stack **a, t_stack **b, char debug__)
{
	if (*a && (*a)->next)
		su_stack__(a);
	if (debug__)
		print_stack(*a, *b, RA);
}

void	rb(t_stack **a, t_stack **b, char debug__)
{
	if (*b && (*b)->next)
		su_stack__(b);
	if (debug__)
		print_stack(*a, *b, RB);
}
