/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_hex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: iazaitce <iazaitce@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/14 18:23:06 by iazaitce      #+#    #+#                 */
/*   Updated: 2025/11/20 16:10:54 by iazaitce      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(unsigned long n)
{
	if (n == 0)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + print_lowhex(n));
}

int	print_lowhex(unsigned long n)
{
	char	*conversion_str;

	conversion_str = "0123456789abcdef";
	if (n > 15)
		return (print_lowhex(n / 16) + print_lowhex(n % 16));
	return (write(1, &conversion_str[n], 1));
}

int	print_uphex(unsigned int n)
{
	char	*conversion_str;

	conversion_str = "0123456789ABCDEF";
	if (n > 15)
		return (print_uphex(n / 16) + print_uphex(n % 16));
	return (write(1, &conversion_str[n], 1));
}
