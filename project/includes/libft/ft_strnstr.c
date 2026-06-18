/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:54:22 by vigomes-          #+#    #+#             */
/*   Updated: 2026/05/13 10:54:22 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *ltl, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(ltl);
	if (j == 0)
		return ((char *)big);
	while (*big && i <= len)
	{
		if (len - i++ >= j && !ft_strncmp(big, ltl, j))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
