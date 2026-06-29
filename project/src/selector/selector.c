/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:37:28 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/29 19:19:22 by vigomes-         ###   ########.fr       */
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

static t_selector	*slc_init(t_parser *parser)
{
	t_selector	*slc;

	slc = malloc(sizeof(t_selector));
	if (!slc)
		return (NULL);
	if (parser->bench)
		slc->bench = 1;
	else
		slc->bench = 0;
	return (slc);
}

t_selector	*selector(t_stack *stack, t_parser	*parser)
{
	t_selector	*slc;
	double		disorder;
	t_stack		*b;

	disorder = ds_global_calculator(stack);
	slc = slc_init(parser);
	if (!slc)
		return (NULL);
	b = malloc(sizeof(t_stack));
	if (!b)
		return (NULL);
	b = NULL;
	if (ft_strcmp(parser->flag, "--simple") == 0)
		slc_filler(slc, 0, disorder);
	else if (ft_strcmp(parser->flag, "--medium") == 0)
		slc_filler(slc, 1, disorder);
	else if (ft_strcmp(parser->flag, "--complex") == 0)
		slc_filler(slc, 2, disorder);
	else if (ft_strcmp(parser->flag, "--adaptive") == 0)
		slc_adaptive(slc, disorder);
	slc->n_ops = runner(slc->id, slc->bench, stack, b);
	return (slc);
}
