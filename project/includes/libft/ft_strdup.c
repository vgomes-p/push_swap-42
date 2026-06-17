/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:53:39 by vigomes-          #+#    #+#             */
/*   Updated: 2026/05/13 10:53:39 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *st)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(ft_strlen(st) + 1);
	if (!str)
		return (NULL);
	while (*st)
		str[i++] = *st++;
	str[i] = '\0';
	return (str);
}
