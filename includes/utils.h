/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jye <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 17:10:14 by jye               #+#    #+#             */
/*   Updated: 2016/12/30 21:08:50 by jye              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# undef INT_MIN
# define INT_MIN 0x80000000
# include <ft_printf.h>

typedef struct	s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				var;
}				t_stack;

/*
** Utils
*/
t_stack			*s_parse(char *str);
t_stack			*av_parse(int ac, char **av);
void			s_check(char *str);
void			av_check(int ac, char **av);
/*
** Stack play
*/
t_stack			*init_stack__(int nb);
void			push_stack__(t_stack **node, int nb);
void			append_stack__(t_stack *node, int nb);
void			pop_stack__(t_stack **node);
void			swap_elem__(t_stack *node);
void			su_stack__(t_stack **node);
void			sd_stack__(t_stack **node);
/*
** Etc function
*/
void			call_exit(void);
int				f_atoi(char *str);
#endif
