/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:03:31 by apereira          #+#    #+#             */
/*   Updated: 2022/11/23 17:11:53 by apereira         ###   ########.fr       */
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
		;
	else if (string[1] == 'd')
		;
	else if (string[1] == 'i')
		;
	else if (string[1] == 'u')
		;
	else if (string[1] == 'x')
		;
	else if (string[1] == 'X')
		;
	else if (string[1] == '%')
		ft_putchar('%');
}

int	ft_printf(const char *string, ...)
{
	if (string[0] == 37)
		ft_check(string);
}
