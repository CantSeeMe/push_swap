/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_order_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 16:18:01 by jye               #+#    #+#             */
/*   Updated: 2017/01/02 17:02:16 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*chk_order_var_norm(t_stack *high_node, int var, char bool__)
{
	t_stack *tmp_node;

	tmp_node = high_node;
	if (bool__)
		while (tmp_node)
		{
			if (tmp_node->var < var)
				return (tmp_node);
			tmp_node = tmp_node->next;
		}
	else
		while (tmp_node)
		{
			if (tmp_node->var > var)
				return (tmp_node);
			tmp_node = tmp_node->next;
		}
	return (NULL);
}

t_stack			*get_s_head(t_stack *cur_head, char bool__)
{
	t_stack	*hvar_node;

	hvar_node = cur_head;
	cur_head = cur_head->next;
	if (bool__)
	{
		while (cur_head)
		{
			if (cur_head->var > hvar_node->var)
				hvar_node = cur_head;
			cur_head = cur_head->next;
		}
		return (hvar_node);
	}
	else
	{
		while (cur_head)
		{
			if (cur_head->var < hvar_node->var)
				hvar_node = cur_head;
			cur_head = cur_head->next;
		}
		return (hvar_node);
	}
}

t_stack			*chk_order_var(t_stack *high_node, int var, char bool__)
{
	t_stack	*head_node;
	t_stack	*tmp_node;

	if ((head_node = get_s_head(high_node, bool__)) != high_node)
	{
		if ((tmp_node = chk_order_var_norm(head_node, var, bool__)))
			return (tmp_node);
	}
	else
		head_node = NULL;
	if (bool__)
		while (high_node != head_node)
		{
			if (high_node->var < var)
				return (high_node);
			high_node = high_node->next;
		}
	else
		while (high_node != head_node)
		{
			if (high_node->var > var)
				return (high_node);
			high_node = high_node->next;
		}
	return (high_node);
}
