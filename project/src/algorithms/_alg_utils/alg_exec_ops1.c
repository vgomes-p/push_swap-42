/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_exec_ops1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 17:12:54 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/08 19:46:56 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../algorithms.h"

void	alg_exec_pa(t_stack **a, t_stack **b, int bench, t_count *count)
{
	op_pa(a, b);
	if (!bench)
		ft_printf("pa\n");
	count->pa++;
	count->total++;
}

void	alg_exec_pb(t_stack **a, t_stack **b, int bench, t_count *count)
{
	op_pb(a, b);
	if (!bench)
		ft_printf("pb\n");
	count->pb++;
	count->total++;
}

void	alg_exec_rra(t_stack **a, int bench, t_count *count)
{
	op_rra(a);
	if (!bench)
		ft_printf("rra\n");
	count->rra++;
	count->total++;
}

void	alg_exec_rrb(t_stack **b, int bench, t_count *count)
{
	op_rrb(b);
	if (!bench)
		ft_printf("rrb\n");
	count->rrb++;
	count->total++;
}

void	alg_exec_rrr(t_stack **a, t_stack **b, int bench, t_count *count)
{
	op_rrr(a, b);
	if (!bench)
		ft_printf("rrr\n");
	count->rrr++;
	count->total++;
}
