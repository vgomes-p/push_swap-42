/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:15:32 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/24 16:24:03 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

//Trocar os dois primeiros nós da stack A.
void	op_sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	if (first->next != NULL)
		first->next->prev = first;
	first->prev = second;
	second->prev = NULL;
	*a = second;
}

void	op_sb(t_stack **b)
{
}

void	op_ss(t_stack **a, t_stack **b)
{
}
