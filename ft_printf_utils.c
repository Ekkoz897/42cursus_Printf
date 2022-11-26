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

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_to_hex(int address, char c)
{
	int		count;

	if (address > 15)
	{
		ft_to_hex(address / 16, c);
		ft_to_hex(address % 16, c);
	}
	else
	{
		if (address < 10)
			ft_putchar(address + '0');
		else
		{
			if (c == 'x')
				ft_putchar(address - 10 + 'a');
			else
				ft_putchar(address - 10 + 'A');
		}
	}
	count = ft_nbr_len(address, 16);
	return (count);
}

int	ft_putnbr(int n, int count)
{
	size_t			i;

	count = ft_nbr_len(n, 10);
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_putstr("-2147483648"));
		ft_putchar('-');
		i = -n;
	}
	else
		i = n;
	if (i > 9)
	{
		ft_putnbr(i / 10, count);
		i %= 10;
	}
	ft_putchar(i + '0');
	return (count);
}

int	ft_putunbr(unsigned int n, int count)
{
	size_t			i;

	i = n;
	if (i > 9)
	{
		ft_putunbr(i / 10, count++);
		i %= 10;
	}
	ft_putchar(i + '0');
	count = ft_nbr_len(n, 10);
	return (count);
}
