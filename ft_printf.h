/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcot <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:25:26 by gcot              #+#    #+#             */
/*   Updated: 2023/02/21 11:27:02 by gcot             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
int		ft_conv(char c, va_list str);
int		ft_format_c(va_list str);
int		ft_format_s(va_list str);
int		ft_format_p(va_list str);
int		ft_format_d_i(va_list str);
int		ft_format_u(va_list str);
int		ft_format_x(va_list str);
int		ft_format_maj(va_list str);
int		ft_format_pour(void);
int		ft_write_null(void);
char	*ft_putnbr_base_adresse(size_t n, char *base);
char	*ft_putnbr_base(unsigned int n, char *base);
char	*ft_itoa(int n);
char	*ft_itoa_u(unsigned int n);
void	ft_putchar(char c);

#endif
