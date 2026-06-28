/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:45:32 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/28 15:01:10 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "runner.h"
// #include "../../includes/push_swap.h"

void place_holder(void)
{
	return ;
}

int	rn_wbench(t_stack *a, t_stack *b, int id)
{
	int	ops;

	ops = 0;
	if (id == 0)
	{
		place_holder();
		ops = alg_n_squared(&a, &b);
	}
	else if (id == 1)
	{
		place_holder();
		ops = alg_n_root(&a, &b);
	}
	else if (id == 2)
	{
		place_holder();
		ops = alg_n_log(&a, &b);
	}
	else
	{
		ops = -1;
		ft_printf("ERROR\n");
	}
	return (ops);
}

int	rn_alg(t_stack *a, t_stack *b, int id)
{
	int	ops;

	ops = 0;
	if (id == 0)
		ops = alg_n_squared(&a, &b);
	else if (id == 1)
		ops = alg_n_root(&a, &b);
	else if (id == 2)
		ops = alg_n_log(&a, &b);
	else
	{
		ops = -1;
		ft_printf("ERROR\n");
	}
	return (ops);
}

int	runner(t_selector *slc, t_stack *a, t_stack *b)
{
	t_stack	*b;
	int	ops;

	ops = 0;
	if (slc->bench)
		ops = rn_wbench(a, b, slc->id);
	else
		ops = rn_alg(a, b, slc->id);
	return (ops);
}