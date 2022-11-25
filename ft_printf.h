/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:06:20 by apereira          #+#    #+#             */
/*   Updated: 2022/11/25 17:11:13 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_to_hex(int address, char c);
int	ft_check(va_list arg, char type);
int	ft_printf(const char *string, ...);
int	ft_putnbr(int n, int count);
int	ft_putunbr(int n, int count);

#endif