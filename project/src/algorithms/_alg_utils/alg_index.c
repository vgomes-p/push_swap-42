/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 17:01:17 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/07 17:13:49 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../algorithms.h"

int	alg_bip(t_stack *stack)
{
	t_stack	*temp;
	int		big_idx;
	int		big_idx_pos;
	int		pos;

	temp = stack;
	big_idx = temp->index;
	big_idx_pos = 0;
	pos = 0;
	while (temp)
	{
		if (temp->index > big_idx)
		{
			big_idx = temp->index;
			big_idx_pos = pos;
		}
		temp = temp->next;
		pos++;
	}
	return (big_idx_pos);
}

int	alg_lip(t_stack *stack)
{
	t_stack	*temp;
	int		low_idx;
	int		low_idx_pos;
	int		pos;
	
	temp = stack;
	low_idx = temp->index;
	low_idx_pos = 0;
	pos = 0;
	while (temp)
	{
		if (temp->index < low_idx)
		{
			low_idx = temp->index;
			low_idx_pos = pos;
		}
		temp = temp->next;
		pos++;
	}
	return (low_idx_pos);
}
