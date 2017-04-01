/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 21:34:35 by jye               #+#    #+#             */
/*   Updated: 2017/01/03 16:53:40 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ft_printf.h>

int		main(int ac, char **av)
{
	t_stack	*stack;
	int		stack_size;

	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		s_check(av[1]);
		if (!(stack = s_parse(av[1])))
			call_exit();
	}
	else
	{
		av_check(ac, av);
		if (!(stack = av_parse(ac, av)))
			call_exit();
	}
	stack_size = sizeof_stack(stack);
	push_swap(&stack, stack_size);
	return (0);
}
