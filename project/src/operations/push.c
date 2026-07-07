/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:15:59 by danda-si          #+#    #+#             */
/*   Updated: 2026/07/03 12:15:39 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

//performs the push operation from the source stack to the destination stack.
static void	op_push(t_stack **src, t_stack **dst)
{
	t_stack	*node;

	if (src == NULL || *src == NULL || dst == NULL)
		return ;
	node = *src;
	*src = node->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	node->next = *dst;
	if (*dst != NULL)
		(*dst)->prev = node;
	node->prev = NULL;
	*dst = node;
}

//performs the push operation from stack b to stack a.
void	op_pa(t_stack **a, t_stack **b)
{
	op_push(b, a);
}

//performs the push operation from stack a to stack b.
void	op_pb(t_stack **a, t_stack **b)
{
	op_push(a, b);
}
