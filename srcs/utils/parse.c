/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:59:25 by jye               #+#    #+#             */
/*   Updated: 2017/01/03 18:27:54 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	check_var(t_stack *high_node, int var)
{
	t_stack *cur_node;

	cur_node = high_node->next;
	while (cur_node)
	{
		if (cur_node->var == var)
			call_exit();
		cur_node = cur_node->next;
	}
}

t_stack		*s_parse(char *str)
{
	t_stack *cur_node;
	t_stack	*high_node;
	int		var;

	if (!(high_node = init_stack__(-1)))
		call_exit();
	cur_node = high_node;
	while (*str)
	{
		var = f_atoi(str);
		check_var(high_node, var);
		append_stack__(cur_node, var);
		cur_node = cur_node->next;
		while (*str == '+' || *str == '-' || (*str >= 0x30 && *str <= 0x39))
			++str;
		if (*str)
			++str;
	}
	pop_stack__(&high_node);
	return (high_node);
}

t_stack		*av_parse(int ac, char **av)
{
	t_stack	*cur_node;
	t_stack	*high_node;
	int		i;
	int		var;

	if (!(high_node = init_stack__(-1)))
		call_exit();
	i = 0;
	cur_node = high_node;
	while (++i < ac)
	{
		var = f_atoi(av[i]);
		check_var(high_node, var);
		append_stack__(cur_node, var);
		cur_node = cur_node->next;
	}
	pop_stack__(&high_node);
	return (high_node);
}

void		s_check(char *str)
{
	while (1)
	{
		if (*str == '-' || *str == '+')
			++str;
		if (!*str)
			call_exit();
		if (*str >= 0x30 && *str <= 0x39)
			while (*str >= 0x30 && *str <= 0x39)
				++str;
		else
			call_exit();
		if (*str == 0x20)
			++str;
		else if (*str == 0)
			return ;
		else
			call_exit();
	}
}

void		av_check(int ac, char **av)
{
	int		i;
	char	*str;

	i = 0;
	while (++i < ac)
	{
		str = av[i];
		while (*str)
		{
			if (*str == '-' || *str == '+')
				++str;
			if (!*str)
				call_exit();
			if (*str >= 0x30 && *str <= 0x39)
				while (*str >= 0x30 && *str <= 0x39)
					++str;
			else
				call_exit();
			if (*str == 0x20)
				call_exit();
		}
	}
}
