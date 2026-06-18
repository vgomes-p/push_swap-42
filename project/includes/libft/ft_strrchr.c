/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:54:25 by vigomes-          #+#    #+#             */
/*   Updated: 2026/05/13 10:54:25 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *st, int c)
{
	int	i;

	i = ft_strlen(st);
	while (i != 0 && st[i] != (char)c)
		i--;
	if (st[i] == (char)c)
		return ((char *)st + i);
	return (NULL);
}
