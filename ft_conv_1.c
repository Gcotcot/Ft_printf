/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:04:42 by gcot              #+#    #+#             */
/*   Updated: 2023/02/21 15:04:46 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_c(va_list str)
{
	char	c;

	c = (char) va_arg(str, int);
	ft_putchar(c);
	return (1);
}

int	ft_format_s(va_list str)
{
	char	*s;
	int		i;

	s = va_arg(str, char *);
	if (!s)
		return (ft_write_null());
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_format_p(va_list str)
{
	int		i;
	int		y;
	char	*c;

	c = ft_putnbr_base_adresse(va_arg(str, size_t), "0123456789abcdef");
	if (!c)
		return (5);
	write(1, "0x", 2);
	i = 2;
	y = 0;
	while (c[y])
	{
		ft_putchar(c[y]);
		y++;
	}
	free(c);
	return (i + y);
}

int	ft_format_d_i(va_list str)
{
	int		i;
	char	*c;

	c = ft_itoa(va_arg(str, int));
	i = 0;
	while (c[i])
	{
		ft_putchar(c[i]);
		i++;
	}
	free(c);
	return (i);
}
