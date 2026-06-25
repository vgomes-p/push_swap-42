/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:15:32 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/25 14:31:44 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

//Trocar os dois primeiros nós da stack A.
static	void	op_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	if (first != NULL)
		first->next->prev = first;
	first->prev = second;
	second->prev = NULL;
	*stack = second;
}

void	op_sa(t_stack **a)
{
	op_swap(a);
}

void	op_sb(t_stack **b)
{
	op_swap(b);
}

void	op_ss(t_stack **a, t_stack **b)
{
	op_swap(a);
	op_swap(b);
}
