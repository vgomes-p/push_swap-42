/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 12:37:21 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/17 14:23:04 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_char(va_list *args)
{
	char	arg;

	arg = (char)va_arg(*args, int);
	return (ft_putchar(arg));
}

int	handle_string(va_list *args)
{
	char	*arg;

	arg = va_arg(*args, char *);
	if (!arg)
		arg = "(null)";
	return (ft_putstr(arg));
}

int	handle_int(va_list *args)
{
	int		arg;
	int		cnt;
	char	*a;

	cnt = 0;
	arg = va_arg(*args, int);
	a = ft_itoa(arg);
	cnt = ft_putstr(a);
	free(a);
	return (cnt);
}

int	handle_unsigned_int(va_list *args)
{
	unsigned int	arg;
	int				cnt;
	char			*a;

	cnt = 0;
	arg = va_arg(*args, unsigned int);
	a = ft_uitoa(arg);
	cnt = ft_putstr(a);
	free(a);
	return (cnt);
}

int	handle_ptr(va_list *args)
{
	void			*arg;
	unsigned long	narg;
	int				cnt;

	cnt = 0;
	arg = va_arg(*args, void *);
	if (arg)
	{
		narg = (unsigned long)arg;
		cnt += ft_putstr("0x");
		cnt += ft_puthexdec("0123456789abcdef", narg);
		return (cnt);
	}
	cnt = ft_putstr("(nil)");
	return (cnt);
}
