/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_calculator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:31:44 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/10 19:49:07 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


double	calculate_local_disorder(t_stack *stack) // less efficient
{
	double	disordered;
	double	pair_nb;
	t_stack	*current;
	t_stack	*next;

	if (ft_stack_is_sorted(stack))
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

/*wip*/
double	calculate_global_disorder(t_stack *stack) // more efficient
{
	double	disordered;
	double	pair_nb;
	t_stack	*current;
	t_stack	*next;

	if (ft_stack_is_sorted(stack))
		return (0);
	current = stack;
	next = stack->next;
	disordered = 0;
	pair_nb = 0;
	return (disordered / pair_nb);
}
