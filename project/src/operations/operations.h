/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:09:38 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/28 11:58:53 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../stack/stack.h"

typedef struct s_stack t_stack;

void	op_sa(t_stack **a);
void	op_sb(t_stack **b);
void	op_ss(t_stack **a, t_stack **b);

void	op_pa(t_stack **a, t_stack **b);
void	op_pb(t_stack **a, t_stack **b);

void	op_ra(t_stack **a);
void	op_rb(t_stack **b);
void	op_rr(t_stack **a, t_stack **b);

void	op_rra(t_stack **a);
void	op_rrb(t_stack **b);
void	op_rrr(t_stack **a, t_stack **b);

#endif