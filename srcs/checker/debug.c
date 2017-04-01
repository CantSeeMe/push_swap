/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 18:41:44 by jye               #+#    #+#             */
/*   Updated: 2017/01/01 19:32:00 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <ft_printf.h>

void	print_stack(t_stack *a, t_stack *b, char *inst)
{
	ft_printf(D);
	ft_printf("|                               %-32s|\n", inst);
	ft_printf(D);
	ft_printf("|                 %-15c|               %-15c|\n", 'a', 'b');
	ft_printf(D);
	while (a || b)
	{
		if (a && b)
			ft_printf("|                % -16d|              % -16d|\n"
					, a->var, b->var);
		else if (b)
			ft_printf("|%32s|              % -16d|\n"
						, "", b->var);
		else if (a)
			ft_printf("|                % -16d|%30s|\n"
						, a->var, "");
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	ft_printf(D);
}
