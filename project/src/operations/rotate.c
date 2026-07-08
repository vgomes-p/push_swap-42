/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:16:18 by danda-si          #+#    #+#             */
/*   Updated: 2026/07/03 12:20:45 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

//performs the rotate operation on the given stack.
static void	op_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = stack_last(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

//performs the rotate operation on stack a.
void	op_ra(t_stack **a)
{
	op_rotate(a);
}

//performs the rotate operation on stack b.
void	op_rb(t_stack **b)
{
	op_rotate(b);
}

//performs the rotate operation on both stack a and stack b.
void	op_rr(t_stack **a, t_stack **b)
{
	op_rotate(a);
	op_rotate(b);
}
