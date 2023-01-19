/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:48:18 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/01/19 14:49:14 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct		s_stack
{
	int				*array;
	size_t			size;
	size_t			max_size;
}					t_stack;

void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);

#endif
