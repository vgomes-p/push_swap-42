/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_root.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:17:20 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/08 19:45:52 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

static void	alg_nr_update_cnk(t_chunk *cnk)
{
	cnk->start += cnk->chunk;
	cnk->end += cnk->chunk;
	cnk->mid = (cnk->start + cnk->end) / 2;
}

static t_chunk	*alg_nr_init_cnk(t_stack **a)
{
	t_chunk	*cnk;

	cnk = malloc(sizeof(t_chunk));
	if (!cnk)
		return (NULL);
	cnk->chunk = alg_nr_sqrt(stack_size(*a));
	cnk->start = 0;
	cnk->end = cnk->chunk - 1;
	cnk->mid = (cnk->start + cnk->end) / 2;
	cnk->pos = 0;
	return (cnk);
}

static void	alg_nr_back(t_stack **a, t_stack **b, int bench, t_count *count)
{
	int	big_idx_pos;
	int	temp;
	int	len;

	big_idx_pos = 0;
	temp = 0;
	len = stack_size(*b);
	while (*b)
	{
		big_idx_pos = alg_bip(*b);
		temp = big_idx_pos;
		if (temp <= len / 2)
			alg_rb(b, temp, bench, count);
		else
			alg_rrb(b, len - big_idx_pos, bench, count);
		alg_exec_pa(a, b, bench, count);
		len = stack_size(*b);
	}
}

static void	alg_nr_chunk(t_stack **a, t_stack **b, int bench, t_count *count)
{
	t_chunk	*cnk;

	cnk = alg_nr_init_cnk(a);
	while (*a)
	{
		if (stack_is_sorted(*a))
			break ;
		cnk->pos = alg_nr_find_chp(*a, cnk->start, cnk->end);
		if (cnk->pos < 0)
		{
			alg_nr_update_cnk(cnk);
			continue ;
		}
		alg_nr_chr(a, cnk->pos, bench, count);
		alg_exec_pb(a, b, bench, count);
		if ((*b)->index <= cnk->mid)
			alg_exec_rb(b, bench, count);
	}
}

void	alg_n_root(t_stack **a, t_stack **b, int bench, t_count *count)
{
	alg_nr_chunk(a, b, bench, count);
	alg_nr_back(a, b, bench, count);
}
