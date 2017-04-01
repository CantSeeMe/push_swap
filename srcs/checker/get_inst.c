/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 18:42:57 by jye               #+#    #+#             */
/*   Updated: 2017/01/01 19:31:11 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <utils.h>
#include <unistd.h>
#include <libft.h>
#include <stdlib.h>

static int	get_inst_norm(t_stack **a, t_stack **b, char *line, char debug__)
{
	if (!ft_strcmp(line, PB))
		pb(a, b, debug__);
	else if (!ft_strcmp(line, RA))
		ra(a, b, debug__);
	else if (!ft_strcmp(line, RB))
		rb(a, b, debug__);
	else if (!ft_strcmp(line, RR))
		rr(a, b, debug__);
	else
	{
		write(2, "Error\n", 6);
		free(line);
		while (*a)
			pop_stack__(a);
		while (*b)
			pop_stack__(b);
		return (1);
	}
	return (0);
}

int			get_inst(t_stack **a, t_stack **b, char *line, char debug__)
{
	if (!ft_strcmp(line, RRA))
		rra(a, b, debug__);
	else if (!ft_strcmp(line, RRB))
		rrb(a, b, debug__);
	else if (!ft_strcmp(line, RRR))
		rrr(a, b, debug__);
	else if (!ft_strcmp(line, SA))
		sa(a, b, debug__);
	else if (!ft_strcmp(line, SB))
		sb(a, b, debug__);
	else if (!ft_strcmp(line, SS))
		ss(a, b, debug__);
	else if (!ft_strcmp(line, PA))
		pa(a, b, debug__);
	else
		return (get_inst_norm(a, b, line, debug__));
	return (0);
}
