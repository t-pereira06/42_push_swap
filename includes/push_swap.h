/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:48:18 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/01/20 16:34:10 by tsodre-p         ###   ########.fr       */
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
	int			size;
	size_t			max_size;
}					t_stack;

int	size_arg(char *arg);
int	count_stack_size(int argc, char *argv[]);
int	fill_stack(int argc, char *argv, t_stack *stack_a);
int	start_stacks(int argc, char *argv, t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);


#endif
