/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_exec_ops2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 17:12:54 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/09 18:41:19 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../algorithms.h"

void	alg_exec_ra(t_stack **a, int bench, t_count *count)
{
	op_ra(a);
	if (!bench)
		ft_printf("ra\n");
	count->ra++;
	count->total++;
}

void	alg_exec_rb(t_stack **b, int bench, t_count *count)
{
	op_rb(b);
	if (!bench)
		ft_printf("rb\n");
	count->rb++;
	count->total++;
}

void	alg_exec_rr(t_stack **a, t_stack **b, int bench, t_count *count)
{
	op_rr(a, b);
	if (!bench)
		ft_printf("rr\n");
	count->rr++;
	count->total++;
}

void	alg_exec_sa(t_stack **a, int bench, t_count *count)
{
	op_sa(a);
	if (!bench)
		ft_printf("sa\n");
	count->sa++;
	count->total++;
}

void	alg_exec_sb(t_stack **b, int bench, t_count *count)
{
	op_sb(b);
	if (!bench)
		ft_printf("sb\n");
	count->sb++;
	count->total++;
}
