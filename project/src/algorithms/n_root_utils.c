/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_root_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 15:17:20 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/08 18:39:25 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

int	alg_nr_sqrt(int nbr)
{
	int	rt;

	rt = 1;
	while (rt * rt < nbr)
		rt++;
	return (rt);
}

int	alg_nr_find_chp(t_stack *a, int start, int end)
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

void	alg_nr_chr(t_stack **a, int pos, int bench, t_count *count)
{
	int	size;
	int	ops;

	ops = 0;
	size = stack_size(*a);
	if (pos <= size / 2)
		while (ops++ < pos)
			alg_exec_ra(a, bench, count);
	else
		while (ops++ < (size - pos))
			alg_exec_rra(a, bench, count);
}
