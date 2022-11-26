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
		return (ft_putchar(va_arg(arg, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (type == 'p')
		return (ft_to_uhex(va_arg(arg, unsigned long), type));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(arg, int), count));
	else if (type == 'u')
		return (ft_putunbr(va_arg(arg, unsigned int), type));
	else if (type == 'x' || type == 'X')
		return (ft_to_hex(va_arg(arg, unsigned int), type));
	return (ft_putchar('%'));
}

int	ft_printf(const char *string, ...)
{
	int		i;
	int		count;
	va_list	arg;

	va_start(arg, string);
	i = 0;
	count = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			count += ft_check(arg, string[i + 1]);
			i++;
		}
		else
			count += ft_putchar(string[i]);
		i++;
	}
	va_end(arg);
	return (count);
}

int	ft_ptr(unsigned long address, int count)
{
	if (address > 15)
	{
		ft_ptr(address / 16, count);
		ft_ptr(address % 16, count);
	}
	else
	{
		if (address < 10)
			count += ft_putchar(address + '0');
		else
				count += ft_putchar(address - 10 + 'A');
	}
	return (count);	
}

int	ft_nbr_len(unsigned long number, int div_by)
{
	int i;

	i = 0;
	while (number != 0)
	{
		i++;
		number = number / div_by;
	}
	return (i);
}

int	ft_to_uhex(unsigned long address, int count)
{
	count = 0;
	count += ft_putstr("0x") + ft_nbr_len(address, 16);
	ft_ptr(address, count);
	return (count);
}
