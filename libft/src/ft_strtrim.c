/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: iazaitce <iazaitce@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/22 14:33:18 by iazaitce      #+#    #+#                 */
/*   Updated: 2025/06/10 21:08:03 by iazaitce      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	ft_is_in_set(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (true);
		set++;
	}
	return (false);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	while (s1 && (ft_is_in_set(set, *s1) == true))
		s1++;
	i = 0;
	end = 0;
	while (s1[i])
	{
		if (ft_is_in_set(set, s1[i]) == false)
			end = i + 1;
		i++;
	}
	return (ft_substr(s1, 0, end));
}
