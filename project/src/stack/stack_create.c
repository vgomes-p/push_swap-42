/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:39:30 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/20 16:39:52 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

// Cria e inicializa um novo nó da pilha (retorna NULL se falhar).
t_stack	*stack_new(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

//Adiciona um novo nó no (FINAL) da stack.
void	stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last = stack_last(*stack);
	last->next = new_node;
	new_node->prev = last;
}

//Adiciona um novo nó no (INICIO) da stack.
void	stack_add_front(t_stack **stack, t_stack *new_node)
{
	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	new_node->next = *stack;
	(*stack)->prev = new_node;
	*stack = new_node;
}
