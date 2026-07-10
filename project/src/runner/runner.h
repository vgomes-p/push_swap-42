/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:45:43 by vigomes-          #+#    #+#             */
/*   Updated: 2026/07/09 21:14:37 by vigomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUNNER_H
# define RUNNER_H

# include "../stack/stack.h"
# include "../selector/selector.h"

typedef struct s_stack		t_stack;
typedef struct s_selector	t_selector;

int	runner(t_selector *slc, t_stack *a, t_stack *b);

#endif