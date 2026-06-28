/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:11:13 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/28 14:36:02 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int ac, char **av)
{
	// double		disorder;
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
	slc = selector(stack, &parser);
	ft_printf("flag: %s\n", parser.flag);
	ft_printf("bench: %d\n", parser.bench);
	int	d = 100 * slc->disorder;
	ft_printf("disorder returned: %i%%\n", d);
	ft_printf("Strategy: %s\n", slc->strategy);
	ft_printf("id: %i\n", slc->id);
	ft_printf("number of operations: %i\n", slc->n_ops);
	free_stack(&stack);
	free(slc);
	return (0);
}

/* TESTE UNITARIO INDEX */
// int	main(int ac, char **av)
// {
// 	// double		disorder;
// 	t_stack		*stack;
// 	t_stack		*temp;
// 	t_selector	*slc;
// 	t_parser	parser;

// 	stack = NULL;
// 	if (ac < 2)
// 		return (0);
// 	if (!parsing_parse_args(ac, av, &stack, &parser))
// 		return (1);
// 	slc = malloc(sizeof(t_selector));
// 	if (!slc)
// 		return (free_stack(&stack), 1);

// 	temp = stack;
// 	ft_printf("BEFORE SET_INDEX:\n");
// 	while (temp)
// 	{
// 		ft_printf("value: %i | index:%i\n", temp->value, temp->index);
// 		temp = temp->next;
// 	}
	
// 	index_set(stack);
	
// 	ft_printf("AFTER SET_INDEX:\n");
// 	while (stack)
// 	{
// 		ft_printf("value: %i | index:%i\n", stack->value, stack->index);
// 		stack = stack->next;
// 	}
// 	free_stack(&stack);
// 	free(slc);
// 	return (0);
// }