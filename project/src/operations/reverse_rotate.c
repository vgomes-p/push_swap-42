/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:16:47 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/26 16:50:43 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

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

void	op_rra(t_stack **a)
{
	op_reverse_rotate(a);
}

void	op_rrb(t_stack **b)
{
	op_reverse_rotate(b);
}

void	op_rrr(t_stack **a, t_stack **b)
{
	op_reverse_rotate(a);
	op_reverse_rotate(b);
}
