/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:16:59 by gcot              #+#    #+#             */
/*   Updated: 2023/02/23 11:42:15 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_int_u(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n / 10)
	{
		n = n / 10;
		i++;
	}
	if (n > 0)
		i++;
	return (i);
}

char	*ft_itoa_u(unsigned int n)
{
	int		len;
	char	*str;

	len = size_int_u(n);
	str = malloc(sizeof (*str) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (n == 0)
		str[0] = 48;
	while (n / 10)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	if (n > 0)
		str[len] = n + '0';
	return (str);
}
