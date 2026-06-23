/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:22:02 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/23 13:15:52 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../../includes/push_swap.h"

//flag: tipo de algoritmo a ser usado, bench: se o modo benchmark está ativo
//bench: É uma flag que indica se o modo benchmark está ativo. Se bench for 1
typedef struct s_parser
{
	char	*flag;
	int		bench;
}	t_parser;

void	parsing_print_error(void);
int		parsing_parse_args(int argc, char **argv,
							t_stack **a, t_parser *parser);
int		parsing_is_valid_number(char *str);
int		parsing_has_duplicate(t_stack *stack, int value);
int		parsing_is_int_range(long value);

#endif