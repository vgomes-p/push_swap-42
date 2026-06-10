/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:41:24 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/10 19:48:37 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_count
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_count;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
	t_count		count;
	t_strategy	strategy;
	double		disorder;
	int			bench;
}	t_data;

t_stack	*ft_stack_new(int value);
void	ft_stack_add_back(t_stack **stack, t_stack *new_node);
void	ft_stack_add_front(t_stack **stack, t_stack *new_node);
t_stack	*ft_stack_last(t_stack *stack);
int		ft_stack_size(t_stack *stack);
void	ft_free_stack(t_stack **stack);
int		ft_stack_is_sorted(t_stack *stack);

double	calculate_local_disorder(t_stack *stack);
double	calculate_global_disorder(t_stack *stack);

#endif