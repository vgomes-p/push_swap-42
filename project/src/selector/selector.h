/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:15:41 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/15 16:38:02 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECTOR_H
# define SELECTOR_H

# include "../../includes/push_swap.h"

typedef struct	s_selector
{
	double	disorder;
	char	*strategy;
	int		id;
}				t_selector;

double	ds_local_calculator(t_stack *stack);
double	ds_global_calculator(t_stack *stack);

#endif