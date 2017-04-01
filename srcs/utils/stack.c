/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:57:05 by jye               #+#    #+#             */
/*   Updated: 2016/12/30 21:08:18 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

t_stack	*init_stack__(int nb)
{
	t_stack	*ret;

	if ((ret = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		call_exit();
	ret->var = nb;
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}

void	push_stack__(t_stack **node, int nb)
{
	t_stack	*cp_node;

	if ((cp_node = init_stack__(nb)) == NULL)
		call_exit();
	cp_node->next = *node;
	if (*node)
		(*node)->prev = cp_node;
	*node = cp_node;
}

void	pop_stack__(t_stack **node)
{
	t_stack *cp_node;

	cp_node = (*node)->next;
	if (cp_node)
		cp_node->prev = NULL;
	free(*node);
	*node = cp_node;
}

void	swap_elem__(t_stack *node)
{
	t_stack *swap;

	swap = node->next;
	swap->var = swap->var ^ node->var;
	node->var = node->var ^ swap->var;
	swap->var = swap->var ^ node->var;
}

void	call_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
