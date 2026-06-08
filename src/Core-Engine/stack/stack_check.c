/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:39:05 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/08 13:18:45 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Verifica se a pilha está ordenada em ordem crescente
//(retorna 1 se estiver ordenada, 0 caso contrário).
int	ft_stack_is_sorted(t_stack *stack)
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
