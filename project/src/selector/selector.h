/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:15:41 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/23 14:55:23 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECTOR_H
# define SELECTOR_H

# include "../../includes/push_swap.h"

typedef struct s_selector
{
	double	disorder;
	char	*strategy;
	int		id;
}				t_selector;

double	ds_local_calculator(t_stack *stack);
double	ds_global_calculator(t_stack *stack);

void	slc_adaptive(t_selector *slc, double disorder);

#endif