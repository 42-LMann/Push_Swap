/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:48:24 by lmann             #+#    #+#             */
/*   Updated: 2022/05/17 19:20:56 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*rotate_stack(t_stack *stack, bool rev)
{
	if (!stack)
		return (NULL);
	if (!rev)
		return (stack->prev);
	else
		return (stack->next);
}

t_stack	*swap_stack(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (NULL);
	if (stack->next == stack)
		return (stack);
	if (stack->next == stack->prev)
		return (stack->next);
	current = stack->next;
	remove_node(stack->next);
	stack = add_node(stack, current);
	return (current);
}

int	lst_size(t_stack *stack)
{
	int	pos;

	if (!stack)
		return (0);
	pos = 0;
	while (stack != 0)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}
