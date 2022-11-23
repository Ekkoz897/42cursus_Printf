/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:05:33 by apereira          #+#    #+#             */
/*   Updated: 2022/11/23 17:44:38 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_to_hex(int address, char c)
{
	size_t	i;

	if (i > 15)
	{
		ft_to_hex(i / 16, c);
		i %= 16;
	}
	if (i < 10)
		ft_putchar_fd(i + '0');
	else
	{
		if (c == 'x')
			ft_putchar(i - 10 + 'a');
		else
			ft_putchar(i - 10 + 'A');
	}
}
