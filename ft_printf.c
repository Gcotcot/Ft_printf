/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:24:03 by gcot              #+#    #+#             */
/*   Updated: 2023/02/21 11:25:20 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_null(void)
{
	write(1, "(null)", 6);
	return (6);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_conv(char c, va_list str)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_format_c(str);
	else if (c == 's')
		i = ft_format_s(str);
	else if (c == 'p')
		i = ft_format_p(str);
	else if (c == 'd' || c == 'i')
		i = ft_format_d_i(str);
	else if (c == 'u')
		i = ft_format_u(str);
	else if (c == 'x')
		i = ft_format_x(str);
	else if (c == 'X')
		i = ft_format_maj(str);
	else if (c == '%')
		i = ft_format_pour();
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	str;
	int		y;

	y = 0;
	va_start(str, format);
	while (*format)
	{
		if (*format == '%' && *format + 1)
		{
			format++;
			y = y + ft_conv(*format, str);
			format++;
		}
		else
		{
			ft_putchar(*format);
			y++;
			format++;
		}
	}			
	va_end(str);
	return (y);
}
