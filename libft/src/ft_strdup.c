/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: iazaitce <iazaitce@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 14:32:26 by iazaitce      #+#    #+#                 */
/*   Updated: 2025/06/08 19:25:47 by iazaitce      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_s;
	size_t	len;

	len = ft_strlen(s);
	if (!s)
		return (NULL);
	new_s = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s, len + 1);
	return (new_s);
}
