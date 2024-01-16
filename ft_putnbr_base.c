/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:04:19 by gcot              #+#    #+#             */
/*   Updated: 2022/12/07 12:30:42 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	size_int_base(unsigned int n, char *str)
{
	int	i;
	int	len;

	len = ft_len(str);
	i = 0;
	if (n == 0)
		return (1);
	while (n / len)
	{
		n = n / len;
		i++;
	}
	if (n > 0)
		i++;
	return (i);
}

char	*ft_putnbr_base(unsigned int n, char *base)
{
	int		len;
	int		size;
	char	*str;

	len = size_int_base(n, base);
	str = malloc(sizeof (*str) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	size = ft_len(base);
	if (n == 0)
		str[0] = base[0];
	while (n / size)
	{
		str[len] = base[(n % size)];
		n = n / size;
		len--;
	}
	if (n > 0)
		str[len] = base[n];
	return (str);
}
