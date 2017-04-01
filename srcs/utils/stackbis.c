/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 20:33:29 by jye               #+#    #+#             */
/*   Updated: 2016/12/29 20:39:02 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

void	su_stack__(t_stack **node)
{
	t_stack	*cp_node;
	t_stack *high_node;
	t_stack	*low_node;

	cp_node = *node;
	high_node = cp_node;
	low_node = high_node->next;
	while (cp_node->next != NULL)
		cp_node = cp_node->next;
	cp_node->next = high_node;
	high_node->next = NULL;
	high_node->prev = cp_node;
	low_node->prev = NULL;
	*node = low_node;
}

void	sd_stack__(t_stack **node)
{
	t_stack	*cp_node;
	t_stack *high_node;
	t_stack	*low_node;

	cp_node = *node;
	high_node = cp_node;
	while (cp_node->next != NULL)
		cp_node = cp_node->next;
	low_node = cp_node->prev;
	cp_node->prev = NULL;
	high_node->prev = cp_node;
	cp_node->next = high_node;
	low_node->next = NULL;
	*node = cp_node;
}

void	append_stack__(t_stack *node, int nb)
{
	t_stack	*append;

	if (!node)
		return ;
	if (!(append = init_stack__(nb)))
		call_exit();
	node->next = append;
	append->prev = node;
}
