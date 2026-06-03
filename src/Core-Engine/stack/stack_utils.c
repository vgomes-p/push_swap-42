/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:39:38 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/03 17:03:46 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// retorna o último elemento da stack
t_stack	*stack_last(t_stack *stack)
{
	t_stack	*current;

	if (stack == NULL)
		return (NULL);
	current = stack;
	while (current->next)
	{
		current = current->next;
	}
	return (current);
}

int		stack_size(t_stack *stack);