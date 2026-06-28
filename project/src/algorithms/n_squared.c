/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_squared.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:57:44 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/27 18:53:11 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static int	alg_ns_reva(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (*b)
	{
		op_pa(a, b);
		i++;
	}
	return (i);
}
static int	alg_ns_lip(t_stack *stack)
{
	t_stack	*temp;
	int		low_idx;
	int		low_idx_pos;
	int		pos;
	
	temp = stack;
	low_idx = temp->index;
	low_idx_pos = 0;
	pos = 0;
	while (temp)
	{
		if (temp->index < low_idx)
		{
			low_idx = temp->index;
			low_idx_pos = pos;
		}
		temp = temp->next;
		pos++;
	}
	return (low_idx_pos);
}

static int	alg_ns_ra(t_stack **a, int temp)
{
	int	ops;

	ops = 0;
	while (temp)
	{
		op_ra(a);
		ops++;
		temp--;
	}
	return (ops);
}

static int	alg_ns_rra(t_stack **a, int temp)
{
	int	ops;

	ops = 0;
	while (temp)
	{
		op_rra(a);
		ops++;
		temp--;
	}
	return (ops);
}


int	alg_n_squared(t_stack **a, t_stack **b)
{
	int	ops;
	int	len;
	int	low_idx_pos;
	int	temp;

	if (!a || !b)
		return (-1);
	len = stack_size(*a);
	ops = 0;
	while (*a)
	{
		low_idx_pos = alg_ns_lip(*a);
		temp = low_idx_pos;
		if (temp <= len / 2)
			ops += alg_ns_ra(a, temp);
		else
			ops += alg_ns_rra(a, len - low_idx_pos);
		op_pb(a, b);
		ops++;
		len = stack_size(*a);
	}
	ops += alg_ns_reva(a, b);
	return (ops);
}
