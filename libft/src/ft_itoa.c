/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: iazaitce <iazaitce@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/10 18:51:40 by iazaitce      #+#    #+#                 */
/*   Updated: 2025/06/12 19:16:31 by iazaitce      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	n_length(long int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long long	num;
	char		*char_arr;
	size_t		len;

	num = n;
	if (n == 0)
		return (ft_strdup("0"));
	len = n_length(num);
	char_arr = (char *)malloc(sizeof(char) * len + 1);
	if (!char_arr)
		return (NULL);
	char_arr[len] = '\0';
	if (num < 0)
	{
		char_arr[0] = '-';
		num = num * -1;
	}
	while (num > 0)
	{
		len--;
		char_arr[len] = num % 10 + '0';
		num = num / 10;
	}
	return (char_arr);
}
