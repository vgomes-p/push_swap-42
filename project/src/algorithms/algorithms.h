/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:55:55 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/29 18:11:21 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "../../includes/push_swap.h"

int	alg_n_squared(t_stack **a, t_stack **b, int bench);
int	alg_n_log(t_stack *a, t_stack *b, int bench);
int	alg_n_root(t_stack *a, t_stack *b, int bench);

#endif