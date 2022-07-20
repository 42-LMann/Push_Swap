/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:20:59 by lmann             #+#    #+#             */
/*   Updated: 2022/05/17 19:20:56 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*g_stack(void)
{
	static t_stack	stack;

	return (&stack);
}

t_stack	*remove_node(t_stack *stack)
{
	t_stack	*current;

	if (!stack || stack->next == stack)
		return (NULL);
	current = stack->prev;
	current->next = stack->next;
	current = stack->next;
	current->prev = stack->prev;
	return (current);
}

t_stack	*add_node(t_stack *stack, t_stack *new)
{
	if (!stack)
		stack = new;
	else
	{
		stack->prev->next = new;
		new->prev = stack->prev;
	}
	new->next = stack;
	stack->prev = new;
	return (stack);
}

t_stack	*new_node(int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (false);
	new->num = num;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
