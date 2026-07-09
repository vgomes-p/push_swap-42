/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_log.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:57:19 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/09 17:13:37 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static int	alg_nl_msb(t_stack *a)
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

static void	alg_nl_init_rad(t_radix *rad, t_stack **a,
							t_stack **b, t_count *count)
{
	rad->a = a;
	rad->b = b;
	rad->i = 0;
	rad->msb = alg_nl_msb(*a);
	rad->ori_size = stack_size(*a);
	rad->count = count;
}

static void	alg_nl_comp_bit(t_radix *rad, int bench)
{
	int	size;

	size = rad->ori_size;
	while (size--)
	{
		if (((*rad->a)->index >> rad->i) & 1)
			alg_exec_ra(rad->a, bench, rad->count);
		else
			alg_exec_pb(rad->a, rad->b, bench, rad->count);
		if (stack_is_sorted(*rad->a))
			break ;
	}
}

static void	alg_nl_revb(t_radix *rad, int bench)
{
	while (*rad->b)
		alg_exec_pa(rad->a, rad->b, bench, rad->count);
}

void	alg_n_log(t_stack **a, t_stack **b, int bench, t_count *count)
{
	t_radix	rad;

	alg_nl_init_rad(&rad, a, b, count);
	while (rad.i < rad.msb)
	{
		alg_nl_comp_bit(&rad, bench);
		alg_nl_revb(&rad, bench);
		if (stack_is_sorted(*a))
			break ;
		rad.i++;
	}
}
