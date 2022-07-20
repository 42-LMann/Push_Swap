/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:30:17 by lmann             #+#    #+#             */
/*   Updated: 2022/05/17 19:20:57 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	swap(bool a, bool b)
{
	if ((!a && !b) || (a && g_data()->sizea < 2) || (b && g_data()->sizeb < 2))
		return (false);
	if (a)
		g_data()->a = swap_stack(g_data()->a);
	if (b)
		g_data()->b = swap_stack(g_data()->b);
	return (true);
}

bool	push(bool a_to_b)
{
	t_stack	*temp;

	if ((a_to_b && g_data()->sizea == 0) || (!a_to_b && g_data()->sizeb == 0))
		return (false);
	if (a_to_b == true)
	{
		temp = g_data()->a;
		g_data()->a = remove_node(g_data()->a);
		(g_data())->b = add_node(g_data()->b, temp)->prev;
		g_data()->sizea--;
		g_data()->sizeb++;
	}
	else if (a_to_b == false)
	{
		temp = g_data()->b;
		g_data()->b = remove_node(g_data()->b);
		(g_data())->a = add_node(g_data()->a, temp)->prev;
		g_data()->sizeb--;
		g_data()->sizea++;
	}
	return (true);
}

bool	rotate(bool a, bool b, bool rev)
{
	if ((!a && !b) || (a && g_data()->sizea < 2) || (b && g_data()->sizeb < 2))
		return (false);
	if (a && !rev)
		g_data()->a = g_data()->a->next;
	if (b && !rev)
		g_data()->b = g_data()->b->next;
	if (a && rev)
		g_data()->a = g_data()->a->prev;
	if (b && rev)
		g_data()->b = g_data()->b->prev;
	return (true);
}

void	operation( int operation)
{
	if (operation == SA)
		swap(true, false);
	else if (operation == SB)
		swap(false, true);
	else if (operation == SS)
		swap(true, true);
	else if (operation == PA)
		push(false);
	else if (operation == PB)
		push(true);
	else if (operation == RA)
		rotate(true, false, false);
	else if (operation == RB)
		rotate(false, true, false);
	else if (operation == RR)
		rotate(true, true, false);
	else if (operation == RRA)
		rotate(true, false, true);
	else if (operation == RRB)
		rotate(false, true, true);
	else if (operation == RRR)
		rotate(true, true, true);
	print_ops(operation);
	g_data()->move_count++;
}
