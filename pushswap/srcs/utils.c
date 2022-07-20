/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 13:45:30 by lmann             #+#    #+#             */
/*   Updated: 2022/05/20 13:48:02 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_ps(char *arg, int error)
{
	ft_putstr_fd(arg, 2);
	exit(error);
}

void	print_ops(int operation)
{
	if (operation == SA)
		ft_printf("sa\n");
	else if (operation == SB)
		ft_printf("sb\n");
	else if (operation == SS)
		ft_printf("ss\n");
	else if (operation == PA)
		ft_printf("pa\n");
	else if (operation == PB)
		ft_printf("pb\n");
	else if (operation == RA)
		ft_printf("ra\n");
	else if (operation == RB)
		ft_printf("rb\n");
	else if (operation == RR)
		ft_printf("rr\n");
	else if (operation == RRA)
		ft_printf("rra\n");
	else if (operation == RRB)
		ft_printf("rrb\n");
	else if (operation == RRR)
		ft_printf("rrr\n");
}
