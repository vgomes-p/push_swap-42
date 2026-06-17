/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:54:20 by vigomes-          #+#    #+#             */
/*   Updated: 2026/05/13 10:54:20 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *st1, const char *st2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (st1[i] && (st1[i] == st2[i]) && i < (n - 1))
		i++;
	return ((unsigned char)st1[i] - (unsigned char)st2[i]);
}
