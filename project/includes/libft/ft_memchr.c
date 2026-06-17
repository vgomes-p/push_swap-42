/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:53:07 by vigomes-          #+#    #+#             */
/*   Updated: 2026/05/13 10:53:07 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *st, int c, size_t n)
{
	if (n == '\0')
		return (NULL);
	while (n--)
	{
		if (*(char *)st == (char)c)
			return ((char *)st);
		st++;
	}
	return (NULL);
}
