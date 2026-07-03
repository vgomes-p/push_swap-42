/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:15:32 by danda-si          #+#    #+#             */
/*   Updated: 2026/07/03 12:21:21 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

//performs the swap operation on the given stack.
static void	op_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	if (first->next != NULL)
		first->next->prev = first;
	first->prev = second;
	second->prev = NULL;
	*stack = second;
}

//performs the swap operation on stack a.
void	op_sa(t_stack **a)
{
	op_swap(a);
}

//performs the swap operation on stack b.
void	op_sb(t_stack **b)
{
	op_swap(b);
}

//performs the swap operation on both stack a and stack b.
void	op_ss(t_stack **a, t_stack **b)
{
	op_swap(a);
	op_swap(b);
}
