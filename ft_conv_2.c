/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:04:51 by gcot              #+#    #+#             */
/*   Updated: 2023/02/21 15:04:54 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_u(va_list str)
{
	int		i;
	char	*c;

	c = ft_itoa_u(va_arg(str, unsigned int));
	i = 0;
	while (c[i])
	{
		ft_putchar(c[i]);
		i++;
	}
	free(c);
	return (i);
}

int	ft_format_x(va_list str)
{
	int		i;
	char	*c;

	c = ft_putnbr_base(va_arg(str, unsigned int), "0123456789abcdef");
	i = 0;
	while (c[i])
	{
		ft_putchar(c[i]);
		i++;
	}
	free(c);
	return (i);
}

int	ft_format_maj(va_list str)
{
	int		i;
	char	*c;

	c = ft_putnbr_base(va_arg(str, unsigned int), "0123456789ABCDEF");
	i = 0;
	while (c[i])
	{
		ft_putchar(c[i]);
		i++;
	}
	free(c);
	return (i);
}

int	ft_format_pour(void)
{
	ft_putchar('%');
	return (1);
}
