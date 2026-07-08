/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:11:13 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/08 17:34:31 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*a;
	t_selector	*slc;
	t_parser	parser;

	a = NULL;
	if (ac < 2)
		return (0);
	if (!parsing_parse_args(ac, av, &a, &parser))
		return (1);
	if (stack_is_sorted(a))
		return (free_stack(&a), 0);
	index_set(a);
	// slc = selector(a, &parser);
	slc = selector(&a, &parser);
	if (!slc)
		return (free_stack(&a), 1);
	free_stack(&a);
	free(slc);
	return (0);
}
