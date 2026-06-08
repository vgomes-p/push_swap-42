/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 15:41:24 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/08 15:57:44 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

//value: valor do nó da pilha
//index:posição do valor na pilha ordenada(inicialmente -1,será preenchida dep)
//next:ponteiro para o próximo nó da pilha
//prev:ponteiro para o nó anterior da pilha(para facilitar operações de rotação)
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

/* Init */
void	init_data(t_data *data);

/* Parsing */
int		parse_args(int argc, char **argv, t_data *data);
int		is_valid_number(char *str);
int		has_duplicate(t_stack *stack, int value);
void	print_error(void);

/* Stack */
t_stack	*ft_stack_new(int value);
void	ft_stack_add_back(t_stack **stack, t_stack *new_node);
void	ft_stack_add_front(t_stack **stack, t_stack *new_node);
t_stack	*ft_stack_last(t_stack *stack);
int		ft_stack_size(t_stack *stack);
void	ft_free_stack(t_stack **stack);
int		ft_stack_is_sorted(t_stack *stack);

/* Operations */
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

/* Benchmark */
void	print_benchmark(t_data *data);

/* Utils */
long	ft_atol(char *str);
void	ft_free_all(t_data *data);

#endif