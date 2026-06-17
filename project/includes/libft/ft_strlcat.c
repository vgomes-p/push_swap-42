/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:53:53 by vigomes-          #+#    #+#             */
/*   Updated: 2026/05/13 10:53:53 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *s, size_t size)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && i < size)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_dst = ft_strnlen(dst, size);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (len_src + size);
	while (src[i] && (len_dst + 1) < size)
		dst[len_dst++] = src[i++];
	dst[len_dst] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
