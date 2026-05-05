/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_extras.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: iazaitce <iazaitce@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/14 18:17:34 by iazaitce      #+#    #+#                 */
/*   Updated: 2025/11/20 15:00:58 by iazaitce      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	print_str(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_num(long int num)
{
	char	c;
	int		neg;

	neg = 0;
	if (num < 0)
	{
		num = num * -1;
		neg = print_char('-');
	}
	if (num >= 10)
		return (print_num(num / 10) + print_num(num % 10) + neg);
	c = num + '0';
	return (write(1, &c, 1) + neg);
}

int	print_unsigned_dec(unsigned int num)
{
	char	c;

	if (num >= 10)
		return (print_unsigned_dec(num / 10) + print_unsigned_dec(num % 10));
	c = num + '0';
	return (write(1, &c, 1));
}
