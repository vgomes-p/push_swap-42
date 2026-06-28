/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selector.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:15:41 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/28 14:34:16 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECTOR_H
# define SELECTOR_H

# include "../stack/stack.h"

typedef struct s_stack t_stack;

# include "../index/index.h"

void	index_set(t_stack *stack);

typedef struct s_parser t_parser;

typedef struct s_selector
{
	double	disorder;
	char	*strategy;
	int		id;
	int		n_ops;
}				t_selector;

double	ds_local_calculator(t_stack *stack);
double	ds_global_calculator(t_stack *stack);

void		slc_adaptive(t_selector *slc, double disorder);
t_selector	*selector(t_stack *stack, t_parser	*parser);

#endif