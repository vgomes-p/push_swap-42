/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:39:38 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/21 14:29:17 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "stack.h"
#include "../../includes/push_swap.h"

//Retorna o último nó da pilha (ou NULL se a pilha estiver vazia).
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

//Retorna o número de nós na pilha.
int	stack_size(t_stack *stack)
{
	t_stack	*current;
	int		count_stack;

	count_stack = 0;
	current = stack;
	while (current != NULL)
	{
		count_stack++;
		current = current->next;
	}
	return (count_stack);
}

//Libera a memória alocada para a pilha e define o ponteiro da pilha como NULL.
void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (stack == NULL)
		return ;
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
