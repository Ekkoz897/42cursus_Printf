/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:03:31 by apereira          #+#    #+#             */
/*   Updated: 2022/11/28 14:01:14 by apereira         ###   ########.fr       */
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
		return (ft_to_uhex(va_arg(arg, unsigned long long), count));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(arg, size_t), count));
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

void	ft_ptr(unsigned long address)
{
	if (address > 15)
	{
		ft_ptr(address / 16);
		ft_ptr(address % 16);
	}
	else
	{
		if (address < 10)
			ft_putchar(address + '0');
		else
			ft_putchar(address - 10 + 'a');
	}
}

int	ft_nbr_len(unsigned long number, int div_by)
{
	int	i;

	i = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		i++;
		number = number / div_by;
	}
	return (i);
}

int	ft_to_uhex(unsigned long long address, int count)
{
	count = 0;
	count += write(1, "0x", 2);
	if (address < 1)
		count += write(1, "0", 1);
	else
	{
		count += ft_nbr_len(address, 16);
		ft_ptr(address);
	}
	return (count);
}
