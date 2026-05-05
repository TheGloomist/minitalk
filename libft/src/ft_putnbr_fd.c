/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: iazaitce <iazaitce@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/11 20:26:56 by iazaitce      #+#    #+#                 */
/*   Updated: 2025/06/12 19:17:53 by iazaitce      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = num * -1;
	}
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
	}
	num = num % 10 + '0';
	write(fd, &num, 1);
}
