/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:16:47 by danda-si          #+#    #+#             */
/*   Updated: 2026/07/03 12:16:13 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

//performs the reverse rotate operation on the given stack.
static void	op_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	last = stack_last(*stack);
	before_last = last->prev;
	before_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

//performs the reverse rotate operation on stack a.
void	op_rra(t_stack **a)
{
	op_reverse_rotate(a);
}

//performs the reverse rotate operation on stack b.
void	op_rrb(t_stack **b)
{
	op_reverse_rotate(b);
}

//performs the reverse rotate operation on both stack a and stack b.
void	op_rrr(t_stack **a, t_stack **b)
{
	op_reverse_rotate(a);
	op_reverse_rotate(b);
}
