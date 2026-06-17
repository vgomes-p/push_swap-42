/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 17:22:02 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/12 10:37:47 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../../includes/push_swap.h"

int		parsing_valid_number(char *str);
int		parsing_has_duplicate(t_stack *stack, int value);
int		parsing_is_int_range(long value);
int		parsing_parse_args(int argc, char **argv, t_data *data);
void	parsing_print_error(void);

#endif