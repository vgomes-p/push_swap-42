/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:20:51 by danda-si          #+#    #+#             */
/*   Updated: 2026/07/09 16:24:39 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	parsing_has_space(char *arg)
{
	while (*arg)
	{
		if (*arg == ' ')
			return (1);
		arg++;
	}
	return (0);
}

static void	parsing_free_split(char **split)
{
	int	i;

	if (split == NULL)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	parsing_add_arg(char *arg, t_stack **a)
{
	char	**split;
	int		i;

	if (parsing_has_space(arg) == 0)
		return (parsing_add_number(arg, a));
	split = ft_split(arg, ' ');
	if (split == NULL || split[0] == NULL)
		return (parsing_free_split(split), 0);
	i = 0;
	while (split[i])
	{
		if (parsing_add_number(split[i], a) == 0)
			return (parsing_free_split(split), 0);
		i++;
	}
	parsing_free_split(split);
	return (1);
}
