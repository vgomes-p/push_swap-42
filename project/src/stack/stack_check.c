/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:39:05 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/21 14:29:07 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "stack.h"
#include "../../includes/push_swap.h"

//Verifica se a pilha está ordenada em ordem crescente
//(retorna 1 se estiver ordenada, 0 caso contrário).
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
