/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iazaitce <iazaitce@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/11 18:47:17 by iazaitce      #+#    #+#                 */
/*   Updated: 2025/06/12 19:17:27 by iazaitce      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result_str;
	size_t	i;

	if (!s)
		return (NULL);
	result_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result_str)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		result_str[i] = f(i, s[i]);
		i++;
	}
	result_str[i] = '\0';
	return (result_str);
}
