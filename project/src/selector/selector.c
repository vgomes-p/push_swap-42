/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:37:28 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/29 18:15:16 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	slc_filler(t_selector *slc, int id, double disorder)
{
	char	*strategy;

	strategy = NULL;
	if (id == 0)
		strategy = "O(n²)";
	else if (id == 1)
		strategy = "O(n√n)";
	else if (id == 2)
		strategy = "O(n log n)";
	else
		strategy = "error:";
	slc->id = id;
	slc->strategy = strategy;
	slc->disorder = disorder;
}

void	slc_adaptive(t_selector *slc, double disorder)
{
	if (disorder < 0.2)
		slc_filler(slc, 0, disorder);
	else if (disorder >= 0.2 && disorder < 0.5)
		slc_filler(slc, 1, disorder);
	else if (disorder >= 0.5)
		slc_filler(slc, 2, disorder);
}

int	runner(int id, int bench, t_stack *a)
{
	t_stack	*b;
	(void)bench;
	(void)id;
	int	ops;

	b = malloc(sizeof(t_stack));
	if (!b)
		return (-1);
	b = NULL;
	index_set(a);
	ops = alg_n_squared(&a, &b, bench);
	free_stack(&b);
	return (ops);
}

t_selector	*selector(t_stack *stack, t_parser	*parser)
{
	t_selector	*slc;
	double		disorder;

	disorder = ds_global_calculator(stack);
	slc = malloc(sizeof(t_selector));
	if (!slc)
		return (NULL);
	if (ft_strcmp(parser->flag, "--simple") == 0)
		slc_filler(slc, 0, disorder);
	else if (ft_strcmp(parser->flag, "--medium") == 0)
		slc_filler(slc, 1, disorder);
	else if (ft_strcmp(parser->flag, "--complex") == 0)
		slc_filler(slc, 2, disorder);
	else if (ft_strcmp(parser->flag, "--adaptive") == 0)
		slc_adaptive(slc, disorder);
	slc->n_ops = runner(slc, stack);
	return (slc);
}
