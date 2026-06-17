/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:54:00 by vigomes-          #+#    #+#             */
/*   Updated: 2026/05/13 10:54:00 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *st, char (*ftn)(unsigned int, char))
{
	int		i;
	char	*res;

	if (!st || !ftn)
		return (NULL);
	i = 0;
	res = ft_calloc(ft_strlen(st) + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (st[i] != '\0')
	{
		res[i] = ftn(i, st[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
