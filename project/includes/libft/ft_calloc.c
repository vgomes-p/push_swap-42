/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:52:41 by vigomes-          #+#    #+#             */
/*   Updated: 2026/05/13 10:52:41 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	sz;

	if (nmemb != 0 && size > ((size_t)-1) / nmemb)
		return (NULL);
	sz = nmemb * size;
	alloc = malloc(sz);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, sz);
	return (alloc);
}
