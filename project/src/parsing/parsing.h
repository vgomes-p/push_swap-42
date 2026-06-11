/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:22:02 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/11 17:23:25 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../../includes/push_swap.h"

int		is_valid_number(char *str);
int		has_duplicate(t_stack *stack, int value);
int		is_int_range(long value);
int		parse_args(int argc, char **argv, t_data *data);
void	print_error(void);

#endif