/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:40:44 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/18 16:12:35 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

//verificar se a string é um número válido
int	parsing_is_valid_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (str[0] == '+' || str[0] == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int	parsing_has_duplicate(t_stack *stack, int value)
{
	return (1);
}

// Verifica se um numero long cabe dentro de um int.
int	parsing_is_int_range(long value)
{
	if (value < INT_MIN)
		return (0);
	if (value > INT_MAX)
		return (0);
	return (1);
}
