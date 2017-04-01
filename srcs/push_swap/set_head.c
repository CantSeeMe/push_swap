/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_head.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 20:04:50 by jye               #+#    #+#             */
/*   Updated: 2017/01/02 20:22:47 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ft_printf.h>

void	set_head(t_stack *node, int sstack)
{
	t_stack *hvar_node;
	int		n;

	hvar_node = get_s_head(node, 0);
	if ((n = get_opt_ins(node, sstack, hvar_node)) < 0)
	{
		while (n)
		{
			ft_printf("rra\n");
			++n;
		}
	}
	else
	{
		while (n)
		{
			ft_printf("ra\n");
			--n;
		}
	}
}
