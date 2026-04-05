/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 10:05:03 by ayasar            #+#    #+#             */
/*   Updated: 2026/04/05 10:46:38 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list *args, const char format)
{
	if (format == 'c')
		return (ft_print_char(va_arg(*args, int)));
	else if (format == 's')
		return (ft_print_str(va_arg(*args, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(*args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_print_nbr(va_arg(*args, int)));
	else if (format == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), format));
	else if (format == '%')
		return (ft_print_percent());
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print_len;
	va_list	args;

	i = 0;
	print_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '\0')
			break ;
		if (str[i] == '%')
			print_len += ft_format(&args, str[++i]);
		else
			print_len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}
