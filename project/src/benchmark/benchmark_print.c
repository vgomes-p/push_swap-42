/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 10:31:54 by danda-si          #+#    #+#             */
/*   Updated: 2026/07/08 19:48:18 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark.h"

//write a percentage value to stderr with two decimal places
static void	benchmark_print_percent(double disorder)
{
	int	value;
	int	integer;
	int	decimal;

	value = (int)(disorder * 10000);
	integer = value / 100;
	decimal = value % 100;
	ft_putnbr_fd(integer, 2);
	ft_putchar_fd('.', 2);
	if (decimal < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(decimal, 2);
	ft_putstr_fd("%\n", 2);
}

//print the benchmark header information to stderr
static void	benchmark_print_header(t_selector *slc, t_count *count)
{
	ft_putstr_fd("========== BENCHMARK ==========\n", 2);
	ft_putstr_fd("[bench] disorder : ", 2);
	benchmark_print_percent(slc->disorder);
	ft_putstr_fd("[bench] strategy : ", 2);
	ft_putstr_fd(slc->strategy, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] total    : ", 2);
	ft_putnbr_fd(count->total, 2);
	ft_putstr_fd("\n", 2);
}

//print the count of each operation to stderr
static void	benchmark_print_operations(t_count *count)
{
	ft_putstr_fd("[bench] sa  : ", 2);
	ft_putnbr_fd(count->sa, 2);
	ft_putstr_fd("  sb  : ", 2);
	ft_putnbr_fd(count->sb, 2);
	ft_putstr_fd("  ss  : ", 2);
	ft_putnbr_fd(count->ss, 2);
	ft_putstr_fd("  pa  : ", 2);
	ft_putnbr_fd(count->pa, 2);
	ft_putstr_fd("  pb  : ", 2);
	ft_putnbr_fd(count->pb, 2);
	ft_putstr_fd("\n[bench] ra  : ", 2);
	ft_putnbr_fd(count->ra, 2);
	ft_putstr_fd("  rb  : ", 2);
	ft_putnbr_fd(count->rb, 2);
	ft_putstr_fd("  rr  : ", 2);
	ft_putnbr_fd(count->rr, 2);
	ft_putstr_fd("  rra : ", 2);
	ft_putnbr_fd(count->rra, 2);
	ft_putstr_fd("  rrb : ", 2);
	ft_putnbr_fd(count->rrb, 2);
	ft_putstr_fd("  rrr : ", 2);
	ft_putnbr_fd(count->rrr, 2);
	ft_putchar_fd('\n', 2);
}

//print the benchmark results to stderr
void	benchmark_print(t_selector *slc, t_count *count)
{
	if (slc == NULL || count == NULL)
		return ;
	benchmark_print_header(slc, count);
	benchmark_print_operations(count);
}
