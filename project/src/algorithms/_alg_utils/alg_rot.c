/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 16:58:36 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/07 17:13:55 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../algorithms.h"

int	alg_ra(t_stack **a, int temp, int bench)
{
	int	ops;

	ops = 0;
	while (temp)
	{
		if (!bench)
			ft_printf("ra\n");
		op_ra(a);
		ops++;
		temp--;
	}
	return (ops);
}

int	alg_rra(t_stack **a, int temp, int bench)
{
	int	ops;

	ops = 0;
	while (temp)
	{
		if (!bench)
			ft_printf("rra\n");
		op_rra(a);
		ops++;
		temp--;
	}
	return (ops);
}

int	alg_rb(t_stack **b, int temp, int bench)
{
	int	ops;

	ops = 0;
	while (temp)
	{
		if (!bench)
			ft_printf("rb\n");
		op_rb(b);
		ops++;
		temp--;
	}
	return (ops);
}

int	alg_rrb(t_stack **b, int temp, int bench)
{
	int	ops;

	ops = 0;
	while (temp)
	{
		if (!bench)
			ft_printf("rrb\n");
		op_rrb(b);
		ops++;
		temp--;
	}
	return (ops);
}