/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:37:28 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/09 17:46:08 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	slc_filler(t_selector *slc, int id, double disorder, char *flag)
{
	char	*strategy;

	strategy = NULL;
	if (id == -1)
		strategy = "Stack Sorted";
	else if (id == 3)
	{
		strategy = ft_strjoin(flag, " / Stack smaller than 5 | Forced O(n²)");
		id = 0;
	}
	else if (id == 0)
		strategy = ft_strjoin(flag, " / O(n²)");
	else if (id == 1)
		strategy = ft_strjoin(flag, " / O(n√n)");
	else if (id == 2)
		strategy = ft_strjoin(flag, " / O(n log n)");
	else
		strategy = "error:";
	slc->id = id;
	slc->strategy = strategy;
	slc->disorder = disorder;
	free(strategy);
}

static void	slc_adaptive(t_selector *slc, double disorder, t_stack *stack)
{
	if (stack_size(stack) <= 5)
		slc_filler(slc, 3, disorder, "Adaptive");
	else if (disorder < 0.2)
		slc_filler(slc, 0, disorder, "Adaptive");
	else if (disorder >= 0.2 && disorder < 0.5)
		slc_filler(slc, 1, disorder, "Adaptive");
	else if (disorder >= 0.5)
		slc_filler(slc, 2, disorder, "Adaptive");
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

static void	slc_call_filler(t_stack *stack, t_parser *parser,
							t_selector *slc, double disorder)
{
	if (stack_is_sorted(stack))
		slc_filler(slc, -1, disorder, "");
	else if (ft_strcmp(parser->flag, "--simple") == 0)
		slc_filler(slc, 0, disorder, "Simple");
	else if (ft_strcmp(parser->flag, "--medium") == 0)
		slc_filler(slc, 1, disorder, "Medium");
	else if (ft_strcmp(parser->flag, "--complex") == 0)
		slc_filler(slc, 2, disorder, "Complex");
	else if (ft_strcmp(parser->flag, "--adaptive") == 0)
		slc_adaptive(slc, disorder, stack);
}

int	selector(t_stack *stack, t_parser	*parser)
{
	t_selector	*slc;
	double		disorder;
	t_stack		*b;
	int			ret;

	disorder = ds_global_calculator(stack);
	slc = slc_init(parser);
	ret = 0;
	if (!slc)
		return (-1);
	b = malloc(sizeof(t_stack));
	if (!b)
		return (-1);
	b = NULL;
	slc_call_filler(stack, parser, slc, disorder);
	ret = runner(slc, stack, b);
	free(slc);
	return (ret);
}
