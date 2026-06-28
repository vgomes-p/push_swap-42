/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_calculator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:31:44 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/21 14:56:36 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

double	ds_local_calculator(t_stack *stack)
{
	double	disordered;
	double	pair_nb;
	t_stack	*current;
	t_stack	*next;

	if (stack_is_sorted(stack))
		return (0);
	current = stack;
	next = stack->next;
	disordered = 0;
	pair_nb = 0;
	while (current->next)
	{
		if (current->value > next->value)
		{
			disordered++;
		}
		current = current->next;
		next = next->next;
		pair_nb++;
	}
	return (disordered / pair_nb);
}

static double	ds_traversal_invertions(t_stack *stack)
{
	double	inverted;
	t_stack	*current;
	t_stack	*temp;

	inverted = 0;
	current = stack;
	while (current)
	{
		temp = current->next;
		if (!temp)
			break ;
		while (temp)
		{
			if (current->value > temp->value)
				inverted++;
			temp = temp->next;
		}
		current = current->next;
	}
	return (inverted);
}

double	ds_global_calculator(t_stack *stack)
{
	double	inverted;
	double	max_inverted;
	int		stack_sz;
	double	disorder;

	if (!stack)
		return (-1);
	stack_sz = stack_size(stack);
	if (stack_is_sorted(stack) || stack_sz == 1)
		return (0);
	inverted = ds_traversal_invertions(stack);
	max_inverted = stack_sz * (stack_sz - 1) / 2;
	disorder = inverted / max_inverted;
	return (disorder);
}
