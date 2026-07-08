/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_squared.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:57:44 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/08 19:17:16 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"

void	alg_n_squared(t_stack **a, t_stack **b, int bench, t_count *count)
{
	int	len;
	int	low_idx_pos;
	int	temp;

	if (!a || !b)
		return ;
	len = stack_size(*a);
	while (*a)
	{
		low_idx_pos = alg_lip(*a);
		temp = low_idx_pos;
		if (stack_is_sorted(*a))
			break ;
		if (temp <= len / 2)
			alg_ra(a, temp, bench, count);
		else
			alg_rra(a, len - low_idx_pos, bench, count);
		alg_exec_pb(a, b, bench, count);
		len = stack_size(*a);
	}
	while (*b)
		alg_exec_pa(a, b, bench, count);
}
