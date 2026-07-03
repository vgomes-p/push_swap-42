/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:09:38 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/30 12:43:26 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "../stack/stack.h"

typedef struct s_stack	t_stack;

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