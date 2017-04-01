/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 21:22:16 by jye               #+#    #+#             */
/*   Updated: 2017/01/03 17:00:35 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <utils.h>

/*
** function push_swap
*/
void	push_swap(t_stack **stack, int stack_size);
/*
** Free merge
*/
t_stack	*merge_unlock(t_stack *dst, t_stack *to_merge, char c);
/*
** Safety merge
*/
t_stack	*merge_lock(t_stack *dst, t_stack *to_merge, char c);
/*
** Merge sort
*/
t_stack	*merge_sort(t_stack **stack, int stack_size, char c, char lock__);
t_stack	*merge3(t_stack **stack, char c, char lock__);
t_stack	*merge2(t_stack **stack, char c);
t_stack	*merge(t_stack *dst, t_stack *to_merge, char c, char lock__);
/*
** search where to put var in ascending / descending order
*/
t_stack	*chk_order_var(t_stack *dst, int var, char bool__);
/*
** Get head position
*/
t_stack *get_s_head(t_stack *cur_head, char bool__);
/*
** Set back to the actual head
*/
void	set_head(t_stack *node, int sstack);
/*
** etc function
*/
int		sizeof_stack(t_stack *node);
int		get_opt_ins(t_stack *node, int ss_b, t_stack *dst);

#endif
