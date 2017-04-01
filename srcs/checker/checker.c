/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 21:24:23 by jye               #+#    #+#             */
/*   Updated: 2017/01/02 16:28:13 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <utils.h>
#include <libft.h>

int		main(int ac, char **av)
{
	t_stack	*stack;
	char	debug__;

	debug__ = 0;
	if (ac == 1)
		return (0);
	else
	{
		if (!ft_strcmp(av[1], FLAG_V) && (debug__ = 1))
			stack = d_parse(ac, av);
		else
			stack = n_parse(ac, av);
	}
	checker_swap(stack, debug__);
	return (0);
}
