/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_squared.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:57:44 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/07 17:19:17 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"


static int	alg_ns_reva(t_stack **a, t_stack **b, int bench)
{
	int	i;

	i = 0;
	while (*b)
	{
		if (!bench)
			ft_printf("pa\n");
		op_pa(a, b);
		i++;
	}
	return (i);
}

int	alg_n_squared(t_stack **a, t_stack **b, int bench)
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
		low_idx_pos = alg_lip(*a);
		temp = low_idx_pos;
		if (temp <= len / 2)
			ops += alg_ra(a, temp, bench);
		else
			ops += alg_rra(a, len - low_idx_pos, bench);
		op_pb(a, b);
		if (!bench)
			ft_printf("pb\n");
		ops++;
		len = stack_size(*a);
	}
	ops += alg_ns_reva(a, b, bench);
	return (ops);
}
