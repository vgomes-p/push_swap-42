/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexdec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:32:49 by vigomes-          #+#    #+#             */
/*   Updated: 2026/05/27 17:54:28 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* hex base: 0123456789abcdef */
int	ft_puthexdec(char *hex, unsigned long int nbr)
{
	unsigned long int	i;
	unsigned long int	hexlen;
	int					cnt;

	cnt = 0;
	hexlen = ft_strlen(hex);
	if (nbr >= hexlen)
		cnt += ft_puthexdec(hex, nbr / hexlen);
	i = nbr % hexlen;
	cnt += ft_putchar(hex[i]);
	return (cnt);
}
