/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 18:04:12 by jye               #+#    #+#             */
/*   Updated: 2017/01/01 18:51:03 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <utils.h>
#include <unistd.h>
#include <ft_printf.h>
#include <libft.h>
#include <stdlib.h>

t_stack	*d_parse(int ac, char **av)
{
	t_stack	*stack;

	if (ac == 3)
	{
		s_check(av[2]);
		if (!(stack = s_parse(av[2])))
			call_exit();
	}
	else
	{
		av_check(ac - 1, av + 1);
		if (!(stack = av_parse(ac - 1, av + 1)))
			call_exit();
	}
	return (stack);
}

t_stack	*n_parse(int ac, char **av)
{
	t_stack *stack;

	if (ac == 2)
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
	return (stack);
}
