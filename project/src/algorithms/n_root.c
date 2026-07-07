/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_root.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:17:20 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/07 18:39:03 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static int	alg_nr_sqrt(int nbr)
{
	int	rt;

	rt = 1;
	while (rt * rt < nbr)
		rt++;
	return (rt);
}

static int	alg_nr_find_chp(t_stack *a, int start, int end)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->index >= start && a->index <= end)
			return (pos);
		a = a->next;
		pos++;
	}
	return (-1);
}

static int	alg_nr_chr(t_stack **a, int pos, int bench)
{
	int	size;
	int	ops;

	ops = 0;
	size = stack_size(*a);
	if (pos <= size / 2)
		while (ops++ < pos)
		{
			op_ra(a);
			if (!bench)
				ft_printf("ra\n");
		}
	else
		while (ops++ < (size - pos))
		{
			op_rra(a);
			if (!bench)
				ft_printf("rra\n");
		}
	return (ops);
}


static int	alg_nr_back(t_stack **a, t_stack **b, int bench)
{
	int	big_idx_pos;
	int	temp;
	int	len;
	int	ops;

	ops = 0;
	big_idx_pos = 0;
	temp = 0;
	len = stack_size(*b);
	while (*b)
	{
		big_idx_pos = alg_bip(*b);
		temp = big_idx_pos;
		if (temp <= len / 2)
			ops += alg_rb(b, temp, bench);
		else
			ops += alg_rrb(b, len - big_idx_pos, bench);
		op_pa(a, b);
		ops++;
		if (!bench)
			ft_printf("pa\n");
		len = stack_size(*b);
	}
	return (ops);
}

static int	alg_nr_chunk(t_stack **a, t_stack **b, int bench)
{
	int		chunk;
	int		start;
	int		end;
	int		ops;
	int		pos;
	int		mid;

	ops = 0;
	chunk = alg_nr_sqrt(stack_size(*a));
	start = 0;
	end = chunk - 1;
	mid = (start + end) / 2;
	while (*a)
	{
		pos = alg_nr_find_chp(*a, start, end);
		if (pos < 0)
		{
			start += chunk;
			end += chunk;
			mid = (start + end) / 2;
			continue ;
		}
		ops += alg_nr_chr(a, pos, bench);
		op_pb(a, b);
		ops++;
		if (!bench)
			ft_printf("pb\n");
		if ((*b)->index <= mid)
		{
			op_rb(b);
			ops++;
			if (!bench)
				ft_printf("rb\n");
		}
	}
	return (ops);
}

int	alg_n_root(t_stack **a, t_stack **b, int bench)
{
	int	ops;

	ops = alg_nr_chunk(a, b, bench);
	ops += alg_nr_back(a, b, bench);
	return (ops);
}
