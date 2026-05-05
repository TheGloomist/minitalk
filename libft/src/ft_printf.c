/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: iazaitce <iazaitce@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/07/23 19:03:49 by iazaitce      #+#    #+#                 */
/*   Updated: 2026/05/05 17:33:41 by iazaitce      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

static int	conversion_check(va_list args, char format)
{
	if (format == 'c')
		return (print_char(va_arg(args, int)));
	else if (format == 's')
		return (print_str(va_arg(args, char *)));
	else if (format == 'p')
		return (print_pointer(va_arg(args, unsigned long)));
	else if (format == 'd' || format == 'i')
		return (print_num(va_arg(args, int)));
	else if (format == 'u')
		return (print_unsigned_dec(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (print_lowhex(va_arg(args, unsigned int)));
	else if (format == 'X')
		return (print_uphex(va_arg(args, unsigned int)));
	else if (format == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	return_value;

	i = 0;
	return_value = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			return_value += conversion_check(args, format[i]);
		}
		else
			return_value += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (return_value);
}
