/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: iazaitce <iazaitce@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 14:33:27 by iazaitce      #+#    #+#                 */
/*   Updated: 2025/05/22 14:47:52 by iazaitce      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	required_len;
	char	*new_str;

	i = 0;
	required_len = ft_strlen(s) - start;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		required_len = 0;
	if (len > required_len)
		len = required_len;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	while (i < len && s[start])
	{
		new_str[i] = s[start];
		i++;
		start++;
	}
	new_str[i] = '\0';
	return (new_str);
}
