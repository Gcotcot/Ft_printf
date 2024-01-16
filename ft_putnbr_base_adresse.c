/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_adresse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:04:19 by gcot              #+#    #+#             */
/*   Updated: 2023/02/23 11:41:38 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*ft_nil(void)
{
	write(1, "(nil)", 5);
	return (NULL);
}

static int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	size_int_base(size_t n, char *str)
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

char	*ft_putnbr_base_adresse(size_t n, char *base)
{
	int		len;
	int		size;
	char	*str;

	if (n == 0)
		return (ft_nil());
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
