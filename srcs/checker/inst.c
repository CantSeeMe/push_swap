/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 19:35:43 by jye               #+#    #+#             */
/*   Updated: 2016/12/30 20:09:03 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <utils.h>

void	rra(t_stack **a, t_stack **b, char debug__)
{
	if (*a && (*a)->next)
		sd_stack__(a);
	if (debug__)
		print_stack(*a, *b, RRA);
}

void	rrb(t_stack **a, t_stack **b, char debug__)
{
	if (*b && (*b)->next)
		sd_stack__(b);
	if (debug__)
		print_stack(*a, *b, RRB);
}

void	rrr(t_stack **a, t_stack **b, char debug__)
{
	if (*a && (*a)->next)
		sd_stack__(a);
	if (*b && (*b)->next)
		sd_stack__(b);
	if (debug__)
		print_stack(*a, *b, RRR);
}

void	sa(t_stack **a, t_stack **b, char debug__)
{
	if (*a && (*a)->next)
		swap_elem__(*a);
	if (debug__)
		print_stack(*a, *b, SA);
}

void	sb(t_stack **a, t_stack **b, char debug__)
{
	if (*b && (*b)->next)
		swap_elem__(*b);
	if (debug__)
		print_stack(*a, *b, SB);
}
