/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:40:44 by danda-si          #+#    #+#             */
/*   Updated: 2026/07/03 12:04:31 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

//checks if the given string represents a valid integer number.
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

//gets the long value of the string, returns 0 if invalid
int	parsing_has_duplicate(t_stack *stack, int value)
{
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

//checks if the given long value is within the range of a 32-bit signed integer.
int	parsing_is_int_range(long value)
{
	if (value < INT_MIN)
		return (0);
	if (value > INT_MAX)
		return (0);
	return (1);
}
