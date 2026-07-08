/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_log.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:57:19 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/08 19:46:23 by vigomes-         ###   ########.fr       */
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

static int	alg_rl_init_rad(t_radix *rad, t_stack **a)
{
	rad->i = 0;
	rad->msb = alg_rl_msb(*a);
	rad->ori_size = stack_size(*a);
	return (0);
}

void	alg_n_log(t_stack **a, t_stack **b, int bench, t_count *count)
{
	int		size;
	t_radix	*rad;

	rad = malloc(sizeof(t_radix));
	if (!rad)
		return ;
	size = alg_rl_init_rad(rad, a);
	while (rad->i++ <= rad->msb)
	{
		size = rad->ori_size;
		while (size--)
		{
			if (((*a)->index >> rad->i) & 1)
				alg_exec_ra(a, bench, count);
			else
				alg_exec_pb(a, b, bench, count);
			if (stack_is_sorted(*a))
				break ;
		}
		while (*b)
			alg_exec_pa(a, b, bench, count);
		if (stack_is_sorted(*a))
			break ;
	}
	free(rad);
}
