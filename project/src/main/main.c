/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:11:13 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/21 14:58:58 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int ac, char **av)
{
	int			i;
	double		disorder;
	t_stack		*stack;
	t_selector	*slc;

	i = 1;
	slc = malloc(sizeof(t_selector));
	stack = stack_new(ft_atoi(av[i]));
	if (ac >= 2)
	{
		while (av[++i])
			stack_add_back(&stack, stack_new(ft_atoi(av[i])));
		disorder = ds_global_calculator(stack);
		slc_adaptive(slc, disorder);
		i = disorder * 100;
		ft_printf("disorder returned: %i%%\n", i);
		ft_printf("Strategy: %s\n", slc->strategy);
		ft_printf("id: %i\n", slc->id);
		free(slc);
	}
	return (0);
}
