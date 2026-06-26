/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:04:37 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/24 18:31:33 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "index.h"

void	index_set(t_stack *stack)
{
	int		index;
	int		current;
	t_stack	*temp;

	while (stack)
	{
		current = stack->value;
		temp = stack;
		index = 0;
		while (temp)
		{
			if (current > temp->value)
				index++;
			temp = temp->next;
		}
		stack->index = index;
		stack = stack->next;
	}
}
