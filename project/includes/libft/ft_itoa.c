/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:52:56 by vigomes-          #+#    #+#             */
/*   Updated: 2026/05/13 10:52:56 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nb)
{
	long int	abs;
	long int	len;
	char		*st;

	abs = nb;
	len = ft_intlen(abs);
	st = ft_calloc(len + 1, sizeof(char));
	if (!st)
		return (NULL);
	if (abs < 0)
		abs *= -1;
	while (len > 0)
	{
		st[--len] = abs % 10 + '0';
		abs /= 10;
	}
	if (nb < 0)
		st[0] = '-';
	return (st);
}

char	*ft_uitoa(unsigned int nb)
{
	unsigned int	abs;
	unsigned int	len;
	char			*st;

	abs = nb;
	len = ft_intlen(abs);
	st = ft_calloc(len + 1, sizeof(char));
	if (!st)
		return (NULL);
	while (len > 0)
	{
		st[--len] = abs % 10 + '0';
		abs /= 10;
	}
	return (st);
}
