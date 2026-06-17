/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_validations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 13:47:00 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/17 14:22:56 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	validate_eol(const char c)
{
	if (c == '\0')
		return (0);
	else if (c == '\n')
		return (0);
	return (1);
}

static int	validate_indentifier(const char *fstr)
{
	unsigned long int	i;

	i = 0;
	while (fstr[i] != '\0')
	{
		if (fstr[i] != '%')
			i++;
		else
		{
			i++;
			if (!validate_eol(fstr[i]))
				return (0);
			else if (fstr[i] == '%' || fstr[i] == 'c' || fstr[i] == 's'
				|| fstr[i] == 'i' || fstr[i] == 'd' || fstr[i] == 'u'
				|| fstr[i] == 'p' || fstr[i] == 'x' || fstr[i] == 'X')
				i++;
			else
				return (0);
		}
	}
	return (1);
}

int	validate_string(const char *fstr)
{
	if (!fstr)
		return (0);
	if (!validate_indentifier(fstr))
		return (0);
	return (1);
}
