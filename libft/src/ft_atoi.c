/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iazaitce <iazaitce@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/21 16:12:34 by iazaitce      #+#    #+#                 */
/*   Updated: 2025/05/22 14:35:55 by iazaitce      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t		i;
	int			sign;
	int			conv;

	i = 0;
	sign = 1;
	conv = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t' || \
	nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		conv = (conv * 10) + (nptr[i] - '0');
		i++;
	}
	return (conv * sign);
}
