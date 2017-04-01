/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 22:51:57 by jye               #+#    #+#             */
/*   Updated: 2017/01/02 16:28:37 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <libft.h>
# include <utils.h>
# define BUFF_SIZE 64
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RRA "rra"
# define RB "rb"
# define RRB "rrb"
# define RR "rr"
# define RRR "rrr"
# define FLAG_V "-v"
# define D "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --\n"

void	checker_swap(t_stack *a, char debug__);
int		get_line(const int fd, char **line);
int		get_inst(t_stack **a, t_stack **b, char *line, char debug__);
t_stack	*d_parse(int ac, char **av);
t_stack *n_parse(int ac, char **av);
void	print_stack(t_stack *a, t_stack *b, char *inst);
void	rra(t_stack **a, t_stack **b, char debug__);
void	rrb(t_stack **a, t_stack **b, char debug__);
void	rrr(t_stack **a, t_stack **b, char debug__);
void	ra(t_stack **a, t_stack **b, char debug__);
void	rb(t_stack **a, t_stack **b, char debug__);
void	rr(t_stack **a, t_stack **b, char debug__);
void	sa(t_stack **a, t_stack **b, char debug__);
void	sb(t_stack **a, t_stack **b, char debug__);
void	ss(t_stack **a, t_stack **b, char debug__);
void	pb(t_stack **a, t_stack **b, char debug__);
void	pa(t_stack **a, t_stack **b, char debug__);

#endif
