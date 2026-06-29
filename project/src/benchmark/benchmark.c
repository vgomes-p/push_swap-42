/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 10:14:49 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/29 17:54:25 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark.h"

//initialize the benchmark count structure to zero
void	benchmark_init(t_count *count)
{
	if (count == NULL)
		return ;
	ft_bzero(count, sizeof(t_count));
}
