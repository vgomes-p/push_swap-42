/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:11:13 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/23 13:54:14 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// int	main(int ac, char **av)
// {
// 	int			i;
// 	double		disorder;
// 	t_stack		*stack;
// 	t_selector	*slc;

// 	i = 1;
// 	slc = malloc(sizeof(t_selector));
// 	stack = stack_new(ft_atoi(av[i]));
// 	if (ac >= 2)
// 	{
// 		while (av[++i])
// 			stack_add_back(&stack, stack_new(ft_atoi(av[i])));
// 		disorder = ds_global_calculator(stack);
// 		slc_adaptive(slc, disorder);
// 		i = disorder * 100;
// 		ft_printf("disorder returned: %i%%\n", i);
// 		ft_printf("Strategy: %s\n", slc->strategy);
// 		ft_printf("id: %i\n", slc->id);
// 		free(slc);
// 	}
// 	return (0);
// }

int	main(int ac, char **av)
{
	double		disorder;
	t_stack		*stack;
	t_selector	*slc;
	t_parser	parser;

	stack = NULL;
	if (ac < 2)
		return (0);
	if (!parsing_parse_args(ac, av, &stack, &parser))
		return (1);
	slc = malloc(sizeof(t_selector));
	if (!slc)
		return (free_stack(&stack), 1);
	disorder = ds_global_calculator(stack);
	slc_adaptive(slc, disorder);
	ft_printf("flag: %s\n", parser.flag);
	ft_printf("bench: %d\n", parser.bench);
	ft_printf("disorder returned: %i%%\n", (int)(disorder * 100));
	ft_printf("Strategy: %s\n", slc->strategy);
	ft_printf("id: %i\n", slc->id);
	free_stack(&stack);
	free(slc);
	return (0);
}
