/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_squared.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:57:44 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/24 19:33:34 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static int	alg_ns_bgidx(t_stack *stack)
{
	t_stack	*temp;
	int		bigger_index;

	temp = stack;
	while (temp)
	{
		bigger_index = temp->index;
		if (temp->next && temp->next->index > bigger_index)
			bigger_index = temp->next->index;
		temp = temp->index;
	}
	return (bigger_index);
}

int	alg_n_squared(t_stack *a, t_stack *b)
{
	int	i;
	int	len;
	int	bgidx;
	int	temp;

	if (!a || !b)
		return (-1);
	i = 0;
	len = stack_size(a);
	while (a)
	{
		bgidx = alg_ns_bgidx(a);
		temp = bgidx;
		while (temp-- > 0);
		{
			op_pb(a, b);
			i++;
		}
		op_ra(a);
		i++;
		while (bgidx--)
		{
			op_pa(a, b);
			i++;
		}
		op_pb(a, b);
		i++;
	}
	while (b)
	{
		op_pa(a, b);
		i++;
	}
	return (i);
}