/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:41:09 by danda-si          #+#    #+#             */
/*   Updated: 2026/07/03 12:08:15 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

//Prints an error message to the standard error output.
void	parsing_print_error(void)
{
	write (2, "Error\n", 6);
}
