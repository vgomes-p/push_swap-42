/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:30:48 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/12 11:10:04 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "../../includes/push_swap.h"

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

t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new_node);
void	stack_add_front(t_stack **stack, t_stack *new_node);
t_stack	*stack_last(t_stack *stack);
int		stack_size(t_stack *stack);
void	free_stack(t_stack **stack);
int		stack_is_sorted(t_stack *stack);

#endif