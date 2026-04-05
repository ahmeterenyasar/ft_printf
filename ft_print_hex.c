/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 10:05:14 by ayasar            #+#    #+#             */
/*   Updated: 2026/04/05 11:02:07 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, const char format)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_print_hex(n / 16, format);
	}
	if (format == 'x')
	{
		len += ft_print_char("0123456789abcdef"[n % 16]);
	}
	else if (format == 'X')
	{
		len += ft_print_char("0123456789ABCDEF"[n % 16]);
	}
	return (len);
}

static int	ft_ptr_len(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

static void	ft_put_ptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_print_char("0123456789abcdef"[num % 16]);
	}
	else
		ft_print_char("0123456789abcdef"[num]);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		len += write(1, "(nil)", 5);
		return (len);
	}
	len += write(1, "0x", 2);
	ft_put_ptr(ptr);
	len += ft_ptr_len(ptr);
	return (len);
}
