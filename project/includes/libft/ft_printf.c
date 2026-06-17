/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 11:02:36 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/17 14:22:48 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_specifiers(char arg, va_list *args)
{
	int	cnt;

	cnt = 0;
	if (arg == '%')
		return (ft_putchar('%'));
	else if (arg == 'i' || arg == 'd')
		cnt = handle_int(args);
	else if (arg == 'u')
		cnt = handle_unsigned_int(args);
	else if (arg == 'c')
		cnt = handle_char(args);
	else if (arg == 's')
		cnt = handle_string(args);
	else if (arg == 'p')
		cnt = handle_ptr(args);
	else if (arg == 'x')
		cnt = handle_lhex(args);
	else if (arg == 'X')
		cnt = handle_uhex(args);
	return (cnt);
}

int	ft_printf(const char *fstr, ...)
{
	int		i;
	int		cnt;
	va_list	args;

	i = 0;
	cnt = 0;
	va_start(args, fstr);
	if (!validate_string(fstr))
		return (-1);
	while (fstr[i] != '\0')
	{
		if (fstr[i] != '%')
			cnt += ft_putchar(fstr[i]);
		else
		{
			i++;
			cnt += handle_specifiers(fstr[i], &args);
		}
		i++;
	}
	va_end(args);
	return (cnt);
}
