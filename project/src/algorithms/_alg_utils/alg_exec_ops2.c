/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_exec_ops2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 17:12:54 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/10 20:32:41 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../algorithms.h"

void	alg_exec_ra(t_stack **a, t_selector *slc, t_count *count)
{
	op_ra(a);
	if (!slc->bench)
		ft_printf("ra\n");
	count->ra++;
	count->total++;
}

void	alg_exec_rb(t_stack **b, t_selector *slc, t_count *count)
{
	op_rb(b);
	if (!slc->bench)
		ft_printf("rb\n");
	count->rb++;
	count->total++;
}

void	alg_exec_rr(t_stack **a, t_stack **b, t_selector *slc, t_count *count)
{
	op_rr(a, b);
	if (!slc->bench)
		ft_printf("rr\n");
	count->rr++;
	count->total++;
}

void	alg_exec_sa(t_stack **a, t_selector *slc, t_count *count)
{
	op_sa(a);
	if (!slc->bench)
		ft_printf("sa\n");
	count->sa++;
	count->total++;
}

void	alg_exec_sb(t_stack **b, t_selector *slc, t_count *count)
{
	op_sb(b);
	if (!slc->bench)
		ft_printf("sb\n");
	count->sb++;
	count->total++;
}
