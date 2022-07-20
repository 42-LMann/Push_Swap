/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:45:06 by lmann             #+#    #+#             */
/*   Updated: 2022/05/19 11:35:29 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_low_index(void)
{
	int	i;

	i = g_data()->t_args - 4;
	while (g_data()->sizea > 3)
	{
		if (g_data()->a->prev->index <= i)
		{
			operation(RRA);
			operation(PB);
		}
		else if (g_data()->a->index <= i)
			operation(PB);
		else
			operation(RA);
	}
}

void	sort_b(void)
{
	if (g_data()->sizeb == 2 && (!is_stack_b_sorted()))
	{	
		operation (SB);
		return ;
	}
}

void	sort_a(void)
{
	if (g_data()->sizea == 2 && (!is_stack_a_sorted()))
	{	
		operation (SA);
		return ;
	}
	if ((g_data()->a->index > g_data()->a->next->index)
		&& (g_data()->a->index < g_data()->a->prev->index))
		operation(SA);
	else if (g_data()->a->index > ((g_data()->a->prev->index)
			&& (g_data()->a->next->index)))
		operation(RA);
	else if (g_data()->a->index < ((g_data()->a->prev->index)
			&& (g_data()->a->next->index)))
		operation(RRA);
	else if (((g_data()->a->index < (g_data()->a->prev->index))
			&& ((g_data()->a->index) < (g_data()->a->next->index))))
		operation(RRA);
}

void	sort_5(void)
{
	if (!is_stack_a_sorted())
	{
		if (g_data()->sizea >= 4)
		{
			move_low_index();
			sort_b();
		}
		while (!is_stack_a_sorted())
			sort_a();
		while (g_data()->sizeb != 0)
			operation(PA);
	}
}
