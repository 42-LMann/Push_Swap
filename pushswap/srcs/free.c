/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:16:59 by lmann             #+#    #+#             */
/*   Updated: 2022/05/19 11:35:34 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*next;

	if (!stack)
		return ;
	curr = stack;
	while (true)
	{
		next = curr->next;
		free(curr);
		if (next == stack)
			break ;
		curr = next;
	}
}

void	free_data(void)
{
	free_stack(g_data()->a);
	free_stack(g_data()->b);
}
