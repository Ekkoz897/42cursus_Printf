/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:03:31 by apereira          #+#    #+#             */
/*   Updated: 2022/11/25 17:11:24 by apereira         ###   ########.fr       */
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
		return (ft_to_hex(va_arg(arg, int), type));
	else if (type == 'd' || type == 'i')
		ft_putnbr(va_arg(arg, int), count);
	else if (type == 'u')
		ft_putunbr(va_arg(arg, unsigned int), type);
	else if (type == 'x')
		return (ft_to_hex(va_arg(arg, int), type));
	else if (type == 'X')
		return (ft_to_hex(va_arg(arg, int), type));
	else if (type == '%')
		ft_putchar('%');
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
