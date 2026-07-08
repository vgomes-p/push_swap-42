/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 16:58:36 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/08 19:46:45 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../algorithms.h"

void	alg_ra(t_stack **a, int temp, int bench, t_count *count)
{
	while (temp)
	{
		alg_exec_ra(a, bench, count);
		temp--;
	}
}

void	alg_rra(t_stack **a, int temp, int bench, t_count *count)
{
	while (temp)
	{
		alg_exec_rra(a, bench, count);
		temp--;
	}
}

void	alg_rb(t_stack **b, int temp, int bench, t_count *count)
{
	while (temp)
	{
		alg_exec_rb(b, bench, count);
		temp--;
	}
}

void	alg_rrb(t_stack **b, int temp, int bench, t_count *count)
{
	while (temp)
	{
		alg_exec_rrb(b, bench, count);
		temp--;
	}
}
