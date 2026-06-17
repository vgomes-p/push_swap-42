/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:40:27 by vigomes-          #+#    #+#             */
/*   Updated: 2026/05/27 18:04:26 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *st)
{
	unsigned long int	i;

	if (!st)
		return (0);
	i = 0;
	while (st[i] != '\0')
	{
		ft_putchar(st[i]);
		i++;
	}
	return (i);
}

int	ft_putstr_nl(char *st)
{
	unsigned long int	i;
	unsigned long int	st_len;

	if (!st)
		return (0);
	i = 0;
	st_len = ft_strlen(st);
	while (i < st_len - 1)
	{
		ft_putchar(st[i]);
		i++;
	}
	return (i);
}
