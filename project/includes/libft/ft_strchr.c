/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:53:36 by vigomes-          #+#    #+#             */
/*   Updated: 2026/05/13 10:53:36 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *st, int c)
{
	while (*st && *st != (char)c)
		st++;
	if ((char)c == *st)
		return ((char *)st);
	return (0);
}
