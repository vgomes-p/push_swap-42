/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:39:38 by danda-si          #+#    #+#             */
/*   Updated: 2026/07/09 18:21:48 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "stack.h"
#include "../../includes/push_swap.h"

//Returns the last node of the stack.
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

//Return the size of the stack (number of nodes).
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

//frees all nodes in the stack and sets the stack pointer to NULL.
void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (stack == NULL || *stack == NULL)
		return ;
	while ((*stack)->prev != NULL)
		*stack = (*stack)->prev;
	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

// void	free_stack(t_stack **stack)
// {
// 	t_stack	*temp;

// 	if (stack == NULL)
// 		return ;
// 	while (*stack != NULL)
// 	{
// 		temp = (*stack)->next;
// 		free(*stack);
// 		*stack = temp;
// 	}
// }
