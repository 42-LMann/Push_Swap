/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:42:28 by lmann             #+#    #+#             */
/*   Updated: 2022/05/19 11:35:31 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bits(void)
{
	int	max;
	int	mb;
	int	incre;

	max = g_data()->a->index;
	mb = 0;
	incre = 0;
	while (g_data()->a && incre != g_data()->sizea)
	{
		if (g_data()->a->index > max)
			max = g_data()->a->index;
		g_data()->a = g_data()->a->next;
		incre++;
	}
	while ((max >> mb) != 0)
		mb++;
	return (mb);
}

bool	is_stack_b_sorted(void)
{
	t_stack	*current;
	int		incre;

	current = g_data()->b;
	incre = 0;
	if (g_data()->sizeb == 0)
		return (true);
	while (current->next != g_data()->b && incre < g_data()->sizeb)
	{
		if ((current->num < g_data()->b->next->num)
			|| (current->index < current->next->index))
			return (false);
		current = current->next;
		incre++;
	}
	return (true);
}

bool	is_stack_a_sorted(void)
{
	t_stack	*current;
	int		incre;

	current = g_data()->a;
	incre = 0;
	while (current->next != g_data()->a && incre < g_data()->sizea)
	{
		if ((current->num > current->next->num)
			|| (current->index > current->next->index))
			return (false);
		current = current->next;
		incre++;
	}
	return (true);
}

void	radix_sort(void)
{
	int	i;
	int	j;
	int	size;
	int	mb;

	i = 0;
	mb = max_bits();
	size = g_data()->sizea;
	if (is_stack_a_sorted() == true)
		return ;
	while (i < mb)
	{
		j = 0;
		while (j++ < size)
		{
			if (((g_data()->a->index >> i) & 1) == 1)
				operation(RA);
			else
				operation(PB);
		}
		while (g_data()->sizeb != 0)
			operation(PA);
		i++;
	}
}
