/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 17:31:37 by jye               #+#    #+#             */
/*   Updated: 2017/01/01 19:33:18 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		f_atoi(char *str)
{
	long	nb;
	char	sign;

	nb = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		sign = *str == '-' ? -1 : 1;
		str++;
	}
	while (*str >= 0x30 && *str <= 0x39)
	{
		if (sign == -1)
		{
			if (((nb = nb * 10 + (*str - 0x30)) > 0x80000000))
				call_exit();
		}
		else
		{
			if ((nb = nb * 10 + (*str - 0x30)) > 0x7fffffff)
				call_exit();
		}
		++str;
	}
	return ((int)(nb * sign));
}
