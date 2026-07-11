/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_exec_ops3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 17:12:54 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/10 20:33:55 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../algorithms.h"

void	alg_exec_ss(t_stack **a, t_stack **b, t_selector *slc, t_count *count)
{
	op_ss(a, b);
	if (!slc->bench)
		ft_printf("ss\n");
	count->ss++;
	count->total++;
}
