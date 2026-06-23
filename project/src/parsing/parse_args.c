/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:39:49 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/22 12:09:54 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// Processa as flags do programa e atualiza a struct parser.
static int	parsing_is_flag(char *arg, t_parser *parser)
{
	if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		parser->bench = 1;
		return (1);
	}
	if (ft_strncmp(arg, "--simple", 9) == 0)
		parser->flag = "--simple";
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		parser->flag = "--medium";
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		parser->flag = "--complex";
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		parser->flag = "--adaptive";
	else
		return (0);
	return (1);
}

// Valida um número e adiciona um novo nó na stack A.
static int	parsing_add_number(char *arg, t_stack **a)
{
	long	value;

	if (parsing_valid_number(arg) == 0)
		return (0);
	value = ft_atol(arg);
	if (parsing_is_int_range(value) == 0)
		return (0);
	if (parsing_has_duplicate(*a, (int)value) == 1)
		return (0);
	ft_stack_add_back(a, ft_stack_new((int)value));
	return (1);
}

// Percorre os argumentos, processa flags e monta a stack A.
int	parsing_parse_args(int argc, char **argv, t_stack **a, t_parser *parser)
{
	int	i;

	i = 1;
	parser->flag = "--adaptive";
	parser->bench = 0;
	while (i < argc)
	{
		if (parsing_is_flag(argv[i], parser) == 0)
		{
			if (parsing_add_number(argv[i], a) == 0)
			{
				parsing_print_error();
				ft_free_stack(a);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
