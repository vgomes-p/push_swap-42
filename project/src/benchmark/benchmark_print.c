/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 10:31:54 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/29 10:43:12 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark.h"

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

static void	benchmark_print_header(t_selector *slc, t_count *count)
{
	ft_putstr_fd("========== BENCHMARK ==========\n", 2);
	ft_putstr_fd("Disorder : ", 2);
	benchmark_print_percent(slc->disorder);
	ft_putstr_fd("Strategy : ", 2);
	ft_putstr_fd(slc->strategy, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("Total    : ", 2);
	ft_putnbr_fd(count->total, 2);
	ft_putstr_fd("\n\n", 2);
}

static void	benchmark_print_operations(t_count *count)
{
	ft_putstr_fd("sa  : ", 2);
	ft_putnbr_fd(count->sa, 2);
	ft_putstr_fd("\nsb  : ", 2);
	ft_putnbr_fd(count->sb, 2);
	ft_putstr_fd("\nss  : ", 2);
	ft_putnbr_fd(count->ss, 2);
	ft_putstr_fd("\npa  : ", 2);
	ft_putnbr_fd(count->pa, 2);
	ft_putstr_fd("\npb  : ", 2);
	ft_putnbr_fd(count->pb, 2);
	ft_putstr_fd("\nra  : ", 2);
	ft_putnbr_fd(count->ra, 2);
	ft_putstr_fd("\nrb  : ", 2);
	ft_putnbr_fd(count->rb, 2);
	ft_putstr_fd("\nrr  : ", 2);
	ft_putnbr_fd(count->rr, 2);
	ft_putstr_fd("\nrra : ", 2);
	ft_putnbr_fd(count->rra, 2);
	ft_putstr_fd("\nrrb : ", 2);
	ft_putnbr_fd(count->rrb, 2);
	ft_putstr_fd("\nrrr : ", 2);
	ft_putnbr_fd(count->rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	benchmark_print(t_selector *slc, t_count *count, double disorder)
{
	(void)disorder;
	if (slc == NULL || count == NULL)
		return ;
	benchmark_print_header(slc, count);
	benchmark_print_operations(count);
}
