/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 18:07:11 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/29 10:14:46 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark.h"

static int	benchmark_count_swap(t_count *count, char *operation)
{
	if (ft_strncmp(operation, "sa", 3) == 0)
		return (count->sa++, count->total++, 1);
	if (ft_strncmp(operation, "sb", 3) == 0)
		return (count->sb++, count->total++, 1);
	if (ft_strncmp(operation, "ss", 3) == 0)
		return (count->ss++, count->total++, 1);
	return (0);
}

static int	benchmark_count_push(t_count *count, char *operation)
{
	if (ft_strncmp(operation, "pa", 3) == 0)
		return (count->pa++, count->total++, 1);
	if (ft_strncmp(operation, "pb", 3) == 0)
		return (count->pb++, count->total++, 1);
	return (0);
}

static int	benchmark_count_rotate(t_count *count, char *operation)
{
	if (ft_strncmp(operation, "ra", 3) == 0)
		return (count->ra++, count->total++, 1);
	if (ft_strncmp(operation, "rb", 3) == 0)
		return (count->rb++, count->total++, 1);
	if (ft_strncmp(operation, "rr", 3) == 0)
		return (count->rr++, count->total++, 1);
	return (0);
}

static int	benchmark_count_reverse(t_count *count, char *operation)
{
	if (ft_strncmp(operation, "rra", 4) == 0)
		return (count->rra++, count->total++, 1);
	if (ft_strncmp(operation, "rrb", 4) == 0)
		return (count->rrb++, count->total++, 1);
	if (ft_strncmp(operation, "rrr", 4) == 0)
		return (count->rrr++, count->total++, 1);
	return (0);
}

void	benchmark_count(t_count *count, char *operation)
{
	if (count == NULL || operation == NULL)
		return ;
	if (benchmark_count_swap(count, operation) == 1)
		return ;
	if (benchmark_count_push(count, operation) == 1)
		return ;
	if (benchmark_count_rotate(count, operation) == 1)
		return ;
	if (benchmark_count_reverse(count, operation) == 1)
		return ;
}
