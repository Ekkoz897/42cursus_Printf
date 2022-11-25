/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:05:33 by apereira          #+#    #+#             */
/*   Updated: 2022/11/25 17:33:40 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_to_hex(int address, char c)
{
	size_t	i;
	int		count;

	count = 0;
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

int	ft_putnbr(int n, int count)
{
	size_t			i;

	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_putstr("-2147483648"));
		ft_putchar('-');
		i = -n;
		count += 1;
	}
	else
		i = n;
	if (i > 9)
	{
		ft_putnbr(i / 10, count);
		i %= 10;
	}
	count += 1;
	ft_putchar(i + '0');
	return (count);
}

int	ft_putunbr(int n, int count)
{
	size_t			i;

	if (n < 0)
	{
		count += ft_putchar('-');
		i = -n;
	}
	else
		i = n;
	if (i > 9)
	{
		ft_putunbr(i / 10, count);
		i %= 10;
	}
	count += 1;
	ft_putchar(i + '0');
	return (count);
}
