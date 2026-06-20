/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:37:28 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/20 16:41:33 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "selector.h"

// static char	*slc_alloc(char *strategy)
// {
// 	char	*str;
// 	size_t	len;

// 	len = (ft_strlen(strategy) + 1);
// 	str = malloc(sizeof(char) * len);
// 	if (!str)
// 		return (NULL);
// 	ft_strlcpy(str, strategy, len);
// 	return (str);
// }

void	slc_filler(t_selector *slc, int id, double disorder)
{
	char *strategy;

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

void	runner(int id, int bench)
{
	(void)id;
	(void)bench;
	return ;
}

int	selector(t_stack *stack, t_parser	*parser)
{
	t_selector	*slc;
	double		disorder;

	disorder = ds_global_calculator(stack);
	slc = malloc(sizeof(t_selector));
	if (!slc)
		return (1);
	if (ft_strcmp(parser->flag, "--simple") == 0)
		slc_filler(slc, 0, disorder);
	else if (ft_strcmp(parser->flag, "--medium") == 0)
		slc_filler(slc, 1, disorder);
	else if (ft_strcmp(parser->flag, "--complex") == 0)
		slc_filler(slc, 2, disorder);
	else if (ft_strcmp(parser->flag, "--adaptive") == 0)
		slc_adaptive(slc, disorder);
	runner(slc->id, parser->bench);
	free(slc);
	return (0);
}
