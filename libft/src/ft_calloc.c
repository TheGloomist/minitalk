/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: iazaitce <iazaitce@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 14:31:47 by iazaitce      #+#    #+#                 */
/*   Updated: 2025/05/29 17:48:18 by iazaitce      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	to_allocate;
	void	*ptr;

	to_allocate = nmemb * size;
	if (to_allocate > INT_MAX)
		return (NULL);
	ptr = malloc(to_allocate);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, to_allocate);
	return (ptr);
}
