/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:45:32 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/08 19:23:39 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "runner.h"

static void	rn_alg(t_stack *a, t_stack *b, t_selector *slc, t_count *count)
{
	if (slc->id == 0)
		alg_n_squared(&a, &b, slc->bench, count);
	else if (slc->id == 1)
		alg_n_root(&a, &b, slc->bench, count);
	else if (slc->id == 2)
		alg_n_log(&a, &b, slc->bench, count);
	else if (slc->id == -1)
		return ;
	else
		ft_printf("ERROR\n");
}

int	runner(t_selector *slc, t_stack *a, t_stack *b)
{
	int		ops;
	t_count	*count;

	count = malloc(sizeof(t_count));
	if (!count)
		return (-1);
	ops = 0;
	rn_alg(a, b, slc, count);
	if (slc->bench)
		benchmark_print(slc, count);
	ops = count->total;
	free(count);
	free(slc);
	free_stack(&b);
	return (ops);
}
