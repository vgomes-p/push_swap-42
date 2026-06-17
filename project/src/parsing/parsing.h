/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:22:02 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/17 15:20:18 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../../includes/push_swap.h"

typedef struct s_parser
{
	char	*flag;
	int		bench;
}	t_parser;

int		parsing_valid_number(char *str);
int		parsing_has_duplicate(t_stack *stack, int value);
int		parsing_is_int_range(long value);
int		parsing_parse_args(int argc, char **argv, t_stack **a,
			t_parser *parser);
void	parsing_print_error(void);

#endif