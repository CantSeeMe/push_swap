/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 16:26:56 by jye               #+#    #+#             */
/*   Updated: 2017/01/02 16:28:08 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <utils.h>
#include <ft_printf.h>
#include <stdlib.h>

static int	is_sorted(t_stack *a)
{
	t_stack *low_node;

	low_node = a->next;
	while (low_node)
	{
		if (a->var > low_node->var)
			return (1);
		a = low_node;
		low_node = low_node->next;
	}
	return (0);
}

void		checker_swap(t_stack *a, char debug__)
{
	t_stack *b;
	char	*line;

	b = NULL;
	while (get_line(0, &line) > 0)
	{
		if (get_inst(&a, &b, line, debug__))
			return ;
		free(line);
	}
	free(line);
	if (b)
		ft_printf("KO\n");
	else if (is_sorted(a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	while (a)
		pop_stack__(&a);
	while (b)
		pop_stack__(&b);
}
