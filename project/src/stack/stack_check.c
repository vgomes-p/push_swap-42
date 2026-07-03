/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:39:05 by danda-si          #+#    #+#             */
/*   Updated: 2026/07/03 11:56:24 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "stack.h"
#include "../../includes/push_swap.h"

//Verifies if the stack is sorted in ascending order
//(returns 1 if sorted, 0 otherwise).
int	stack_is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (stack == NULL || stack->next == NULL)
		return (1);
	current = stack;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
