/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:37:18 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/01/19 14:59:26 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(void)
{
	t_stack	*stack_a;

	ft_printf("%s", "before:");
	ft_printlist(stack_a);
	ft_printf("%s", "\n");
	sa(stack_a);
	//https://github.com/0x050f/push_swap/tree/main/srcs/push_swap/srcs
	return (0);
}

