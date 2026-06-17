/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:54:33 by vigomes-          #+#    #+#             */
/*   Updated: 2026/05/13 10:54:33 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *st, unsigned int start, size_t len)
{
	char	*str;
	size_t	j;

	if (!st)
		return (NULL);
	j = ft_strlen(st);
	if (start >= j)
		return (ft_strdup(""));
	if (j - start >= len)
		str = malloc((len + 1) * sizeof(char));
	else
		str = malloc((j - start + 1) * sizeof(char));
	if (str)
	{
		if (len > j + 1)
			len = j + 1;
		ft_strlcpy(str, (st + start), (len + 1));
	}
	else
		return (NULL);
	return (str);
}
