/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:18:03 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/15 17:18:16 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *st1, const char *st2)
{
	size_t	i;

	i = 0;
	while (st1[i] && (st1[i] == st2[i]))
		i++;
	return ((unsigned char)st1[i] - (unsigned char)st2[i]);
}
