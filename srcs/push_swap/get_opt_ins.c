/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt_ins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 20:11:00 by jye               #+#    #+#             */
/*   Updated: 2017/01/02 20:16:26 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_opt_ins(t_stack *node, int ss_b, t_stack *dst)
{
	t_stack *cur_node;
	int		i;

	i = 0;
	cur_node = node;
	while (cur_node != dst)
	{
		cur_node = cur_node->next;
		++i;
	}
	if (i == ss_b || i == 0)
		return (i);
	else
		i = i < -(i - ss_b) ? i : i - ss_b;
	return (i);
}
