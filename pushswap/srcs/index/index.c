/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:00:57 by lmann             #+#    #+#             */
/*   Updated: 2022/05/17 19:20:55 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int n)
{
	t_stack	*current;
	int		index_val;
	int		incre;

	incre = 0;
	index_val = 0;
	current = g_data()->a;
	while (incre != g_data()->t_args && index_val < g_data()->t_args)
	{
		if (current->num < n)
			index_val++;
		current = current->next;
		incre++;
	}
	return (index_val);
}

void	index_stack(void)
{
	t_stack	*current;
	int		incre;

	current = g_data()->a;
	current->index = 0;
	if (!current)
		return ;
	incre = 0;
	while (current->next == NULL || incre != g_data()->t_args)
	{
		current->index = get_index(current->num);
		current = current->next;
		incre++;
	}
}
