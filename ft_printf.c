/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:03:31 by apereira          #+#    #+#             */
/*   Updated: 2022/11/23 17:55:10 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(char *string)
{
	if (string[1] == 'c')
		ft_putchar();
	else if (string[1] == 's')
		ft_putstr();
	else if (string[1] == 'p')
		ft_to_hex(, string[1]);
	else if (string[1] == 'd')
		;
	else if (string[1] == 'i')
		;
	else if (string[1] == 'u')
		;
	else if (string[1] == 'x')
		ft_to_hex(, string[1]);
	else if (string[1] == 'X')
		ft_to_hex(, string[1]);
	else if (string[1] == '%')
		ft_putchar('%');
}

int	ft_printf(const char *string, ...)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == 37)
			ft_check(string[i + 1]);
		i++;
	}
}
