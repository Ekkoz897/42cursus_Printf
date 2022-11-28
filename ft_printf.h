/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:06:20 by apereira          #+#    #+#             */
/*   Updated: 2022/11/28 14:19:07 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putstr(char *s);
int	ft_putchar(int c);
int	ft_to_hex(unsigned int address, char c);
int	ft_check(va_list arg, char type);
int	ft_printf(const char *string, ...);
int	ft_putnbr(int n, int count);
int	ft_putunbr(unsigned int n, int count);
int	ft_to_uhex(unsigned long long address, int count);
int	ft_nbr_len(unsigned long number, int div_by);

#endif