/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:18:22 by tsodre-p          #+#    #+#             */
/*   Updated: 2023/01/19 11:39:49 by tsodre-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		++len;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*result;
	int		len;

	len = size(n);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	if (n == 0)
		result[0] = '0';
	while (n != 0)
	{
		--len;
		result[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (result);
}
