/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:37:18 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/01/20 14:02:54 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	//https://github.com/0x050f/push_swap/tree/main/srcs/push_swap/srcs
	int	i;

	i = 1;
	if (argc < 2)
	{
		ft_printf("%s", "Please introduce a valid number of arguments!");
		return (0);
	}
	while (i < argc)
	{
		if (!ft_isdigit(ft_atoi(argv[i])))
		{
			ft_printf("%s", "Not all the arguments are numbers!");
			return (0);
		}
	}
	return (0);
}

