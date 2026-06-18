/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 14:57:50 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/17 14:23:00 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_lhex(va_list *args)
{
	unsigned int	arg;

	arg = va_arg(*args, unsigned int);
	return (ft_puthexdec("0123456789abcdef", arg));
}

int	handle_uhex(va_list *args)
{
	unsigned int	arg;

	arg = va_arg(*args, unsigned int);
	return (ft_puthexdec("0123456789ABCDEF", arg));
}
