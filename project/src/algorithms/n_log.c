/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_log.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:57:19 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/04 15:44:27 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static int	alg_rl_msb(t_stack *a)
{
	int		msi;
	int		msb;

	if (!a)
		return (0);
	msb = 0;
	msi = a->index;
	a = a->next;
	while (a)
	{
		if (a->index > msi)
			msi = a->index;
		a = a->next;
	}
	while (msi > 0)
	{
		msi >>= 1;
		msb++;
	}
	return (msb);
}

static int alg_rl_radix(t_stack *a, t_stack *b, int bench)
{
	int	msb;
	int	size;
	int	ori_size;
	int	ops;
	int	i;

	ops = 0;
	i = 0;
	msb = alg_rl_msb(a);
	ori_size = stack_size(a);
	while (i <= msb)
	{
		size = ori_size;
		while (size--)
		{
			if ((a->index >> i) & 1)
			{
				if (!bench)
					ft_printf("ra\n");
				op_ra(&a);
				ops++;
			}
			else
			{
				if (!bench)
					ft_printf("pb\n");
				op_pb(&a, &b);
				ops++;
			}
			if (stack_is_sorted(a))
				break ;
		}
		while (b)
		{
			op_pa(&a, &b);
			if (!bench)
				ft_printf("pa\n");
			ops++;
		}
		if (stack_is_sorted(a))
			break ;
		i++;
	}
	return (ops);
}

int	alg_n_log(t_stack **a, t_stack **b, int bench)
{
	int	ops;

	ops = alg_rl_radix(*a, *b, bench);
	return (ops);
}
