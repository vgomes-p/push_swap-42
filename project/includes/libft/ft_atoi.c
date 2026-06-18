/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:52:31 by vigomes-          #+#    #+#             */
/*   Updated: 2026/05/13 10:52:31 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *st)
{
	int	s;
	int	res;
	int	c;

	s = 1;
	res = 0;
	c = 0;
	while ((*st >= '\t' && *st <= '\r') || *st == ' ')
		st++;
	if (*st == '-' || *st == '+')
	{
		if (c > 0)
			return (0);
		if (*st++ == '-')
			s *= -1;
		c++;
	}
	while (ft_isdigit(*st))
		res = (res * 10) + (*st++ - '0');
	return (res * s);
}
