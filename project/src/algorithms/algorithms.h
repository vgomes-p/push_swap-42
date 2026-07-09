/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 18:55:55 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/09 14:53:06 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

# include "../../includes/push_swap.h"

typedef struct s_count	t_count;
typedef struct s_stack	t_stack;

typedef struct s_radix
{
	t_stack	**a;
	t_stack	**b;
	t_count	*count;
	int		msb;
	int		ori_size;
	int		i;
}				t_radix;

typedef struct s_chunk
{
	int	chunk;
	int	start;
	int	end;
	int	mid;
	int	pos;
}				t_chunk;

void	alg_exec_pa(t_stack **a, t_stack **b, int bench, t_count *count);
void	alg_exec_pb(t_stack **a, t_stack **b, int bench, t_count *count);
void	alg_exec_rra(t_stack **a, int bench, t_count *count);
void	alg_exec_rrb(t_stack **b, int bench, t_count *count);
void	alg_exec_rrr(t_stack **a, t_stack **b, int bench, t_count *count);
void	alg_exec_ra(t_stack **a, int bench, t_count *count);
void	alg_exec_rb(t_stack **b, int bench, t_count *count);
void	alg_exec_rr(t_stack **a, t_stack **b, int bench, t_count *count);
void	alg_exec_sa(t_stack **a, int bench, t_count *count);
void	alg_exec_sb(t_stack **b, int bench, t_count *count);
void	alg_exec_ss(t_stack **a, t_stack **b, int bench, t_count *count);

void	alg_ra(t_stack **a, int temp, int bench, t_count *count);
void	alg_rra(t_stack **a, int temp, int bench, t_count *count);
void	alg_rb(t_stack **b, int temp, int bench, t_count *count);
void	alg_rrb(t_stack **b, int temp, int bench, t_count *count);

int		alg_bip(t_stack *stack);
int		alg_lip(t_stack *stack);

int		alg_nr_sqrt(int nbr);
int		alg_nr_find_chp(t_stack *a, int start, int end);
void	alg_nr_chr(t_stack **a, int pos, int bench, t_count *count);

void	alg_n_squared(t_stack **a, t_stack **b, int bench, t_count *count);
void	alg_n_log(t_stack **a, t_stack **b, int bench, t_count *count);
void	alg_n_root(t_stack **a, t_stack **b, int bench, t_count *count);

#endif