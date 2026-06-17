/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:40:44 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/17 15:05:45 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

int	parsing_is_int_range(long value)
{
	return (1);
}
