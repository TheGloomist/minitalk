/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iazaitce <iazaitce@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/19 14:24:24 by iazaitce      #+#    #+#                 */
/*   Updated: 2025/06/12 19:13:54 by iazaitce      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*temp;

	if (!dest && !src)
		return (NULL);
	temp = (char *)src;
	if (temp < (char *)dest)
	{
		while (n--)
			*(char *)(dest + n) = temp[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
