/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 16:11:13 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/08 18:35:42 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*a;
	t_parser	parser;
	int			ret;

	a = NULL;
	if (ac < 2)
		return (0);
	if (!parsing_parse_args(ac, av, &a, &parser))
		return (1);
	index_set(a);
	ret = selector(a, &parser);
	free_stack(&a);
	return (ret);
}
