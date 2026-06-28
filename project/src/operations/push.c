/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:15:59 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/25 16:15:38 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

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

void	op_pa(t_stack **a, t_stack **b)
{
	op_push(b, a);
}

void	op_pb(t_stack **a, t_stack **b)
{
	op_push(a, b);
}
