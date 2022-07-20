/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:48:01 by lmann             #+#    #+#             */
/*   Updated: 2022/05/20 13:27:32 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*g_data(void)
{
	static t_data	data;

	return (&data);
}

static void	init_data(void)
{
	g_data()->a = NULL;
	g_data()->b = NULL;
	g_data()->sizea = 0;
	g_data()->sizeb = 0;
	g_data()->move_count = 0;
	g_data()->t_args = 0;
}

bool	checking_args(int n, char **values)
{
	t_stack	*new;
	int		num;

	if (!values)
		return (false);
	init_data();
	while (g_data()->sizea + 1 < n)
	{
		num = ft_atoi(values[g_data()->sizea + 1]);
		if (!single_arg_check(values[g_data()->sizea + 1])
			|| dup_check(g_data()->a, num))
		{
			free_stack(g_data()->a);
			ft_exit_ps("Error\n", 0);
		}
		new = new_node(num);
		(g_data())->a = add_node(g_data()->a, new);
		g_data()->sizea++;
	}
	g_data()->t_args = g_data()->sizea;
	return (true);
}

int	main(int argc, char *argv[argc])
{
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	else if (!checking_args(argc, argv))
		ft_exit_ps("Error\n", 0);
	index_stack();
	if (argc < 7)
		sort_5();
	else
	{
		radix_sort();
		if (is_stack_a_sorted() == false)
			radix_sort();
	}
	free_data();
	return (0);
}
