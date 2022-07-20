/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:53:23 by lmann             #+#    #+#             */
/*   Updated: 2022/05/17 19:20:54 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>

# define SA 0 
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_data
{
	t_stack			*a;
	t_stack			*b;
	int				sizea;
	int				sizeb;
	int				move_count;
	int				t_args;
}	t_data;

t_data		*g_data(void);
t_stack		*g_stack(void);

t_stack		*remove_node(t_stack *stack);
t_stack		*add_node(t_stack *stack, t_stack *new);
t_stack		*new_node(int num);

t_stack		*rotate_stack(t_stack *stack, bool rev);
t_stack		*swap_stack(t_stack *stack);

int			lst_size(t_stack *stack);

bool		swap(bool a, bool b);
bool		push(bool a_to_b);
bool		rotate(bool a, bool b, bool rev);
void		operation(int operation);

void		move_low_index(void);
void		sort_5(void);
void		radix_sort(void);
int			max_bits(void);

int			get_index(int n);
void		index_stack(void);

bool		dup_check(t_stack *stack, int num);
bool		single_arg_check(char *value);
bool		is_stack_a_sorted(void);
bool		is_stack_b_sorted(void);

void		ft_exit_ps(char *arg, int error);
void		print_ops(int operation);

void		free_data(void);
void		free_stack(t_stack *stack);

#endif