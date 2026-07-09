/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:39:49 by danda-si          #+#    #+#             */
/*   Updated: 2026/07/09 16:23:51 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// Converts a string to a long integer, handling optional '+' or '-' signs.
static long	parsing_atol(char *str)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return (nbr * sign);
}

//Sets the strategy flag in the parser based on the argument provided.
static int	parsing_set_strategy(char *arg, t_parser *parser, int *count)
{
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
	(*count)++;
	if (*count > 1)
		return (-1);
	return (1);
}

//Checks if the argument is a recognized flag and updates the parser.
static int	parsing_is_flag(char *arg, t_parser *parser, int *strat, int *bench)
{
	if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		(*bench)++;
		if (*bench > 1)
			return (-1);
		parser->bench = 1;
		return (1);
	}
	return (parsing_set_strategy(arg, parser, strat));
}

// Parses a single argument, adding it to the stack if it's a valid number.
int	parsing_add_number(char *arg, t_stack **a)
{
	long	value;
	t_stack	*new_node;

	if (parsing_is_valid_number(arg) == 0)
		return (0);
	value = parsing_atol(arg);
	if (parsing_is_int_range(value) == 0)
		return (0);
	if (parsing_has_duplicate(*a, (int)value) == 1)
		return (0);
	new_node = stack_new((int)value);
	if (!new_node)
		return (0);
	stack_add_back(a, new_node);
	return (1);
}

// Parses command-line arguments, populating the stack and parser structure.
int	parsing_parse_args(int argc, char **argv, t_stack **a, t_parser *parser)
{
	int	i;
	int	flag_status;
	int	strategy_count;
	int	bench_count;

	i = 1;
	strategy_count = 0;
	bench_count = 0;
	parser->flag = "--adaptive";
	parser->bench = 0;
	while (i < argc)
	{
		flag_status = parsing_is_flag(argv[i], parser, &strategy_count,
				&bench_count);
		if (flag_status == -1 || (flag_status == 0
				&& parsing_add_arg(argv[i], a) == 0))
		{
			parsing_print_error();
			free_stack(a);
			return (0);
		}
		i++;
	}
	return (1);
}
