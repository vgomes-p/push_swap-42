/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:54:29 by vigomes-          #+#    #+#             */
/*   Updated: 2026/05/13 10:54:29 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *st, char const *set)
{
	char	*str;
	size_t	i;

	if (!st || !set)
		return (NULL);
	while (*st && ft_strchr(set, *st))
		st++;
	i = ft_strlen(st) + 1;
	while (i && ft_strchr(set, st[i - 1]))
		i--;
	str = (char *) malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, st, i + 1);
	return (str);
}
