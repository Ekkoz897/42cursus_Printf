/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:03:31 by apereira          #+#    #+#             */
/*   Updated: 2022/11/25 17:32:53 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list arg, char type)
{
	int	count;

	count = 0;
	if (type == 'c')
		return (ft_putchar(va_arg(arg, char)));
	else if (type == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (type == 'p')
		return (ft_to_uhex(va_arg(arg, unsigned long), type));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(arg, int), count));
	else if (type == 'u')
		return (ft_putunbr(va_arg(arg, unsigned int), type));
	else if (type == 'x')
		return (ft_to_hex(va_arg(arg, unsigned int), type));
	else if (type == 'X')
		return (ft_to_hex(va_arg(arg, unsigned int), type));
	else if (type == '%')
		return (ft_putchar('%'));
}

int	ft_printf(const char *string, ...)
{
	int		i;
	va_list	arg;
	int		count;

	va_start(arg, string);
	i = 0;
	count = 0;
	while (string[i])
	{
		if (string[i++] == '%')
			count += ft_check(arg, string[i++]);
		else
			count += ft_putchar(string[i++]);
	}
	va_end(arg);
	return (count);
}

int	ft_to_uhex(unsigned long address, char c)
{
	unsigned long	i;
	int				count;

	count = 0;
	count += ft_putstr("0x");
	if (address > 15)
	{
		ft_to_hex(address / 16, c);
		i = address % 16;
	}
	if (i < 10)
		count += ft_putchar(i + '0');
	else
	{
		if (c == 'x')
			count += ft_putchar(i - 10 + 'a');
		else
			count += ft_putchar(i - 10 + 'A');
	}
	return (count);
}
