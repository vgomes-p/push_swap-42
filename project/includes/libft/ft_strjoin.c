/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 10:53:51 by vigomes-          #+#    #+#             */
/*   Updated: 2026/05/13 10:53:51 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *st1, char const *st2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(st1);
	len2 = ft_strlen(st2);
	str = malloc((len1 + len2 + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, st1, len1 + 1);
	ft_strlcpy(&str[len1], st2, len2 + 1);
	return (str);
}
