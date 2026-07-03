/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 14:45:43 by vigomes-          #+#    #+#             */
/*   Updated: 2026/06/30 12:50:49 by danda-si         ###   ########.fr       */
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