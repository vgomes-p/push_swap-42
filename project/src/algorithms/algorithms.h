/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:55:55 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/07 18:39:52 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "../../includes/push_swap.h"

int	alg_ra(t_stack **a, int temp, int bench);
int	alg_rra(t_stack **a, int temp, int bench);
int	alg_rb(t_stack **b, int temp, int bench);
int	alg_rrb(t_stack **b, int temp, int bench);

int	alg_bip(t_stack *stack);
int	alg_lip(t_stack *stack);

int	alg_n_squared(t_stack **a, t_stack **b, int bench);
int	alg_n_log(t_stack **a, t_stack **b, int bench);
int	alg_n_root(t_stack **a, t_stack **b, int bench);

#endif