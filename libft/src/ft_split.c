/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: iazaitce <iazaitce@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/10 16:44:08 by iazaitce      #+#    #+#                 */
/*   Updated: 2025/06/12 20:25:21 by iazaitce      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	i;
	int	w_count;

	i = 0;
	w_count = 0;
	if (s[0] == '\0')
		return (0);
	if (c == '\0')
		return (1);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		w_count++;
		while (s[i] == c)
			i++;
	}
	return (w_count);
}

static int	get_len(char const *s, char c)
{
	int	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

static char	**handle_error(char **s, int const len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (s[i])
		{
			free(s[i]);
			s[i] = NULL;
		}
		i++;
	}
	free(s);
	s = NULL;
	return (NULL);
}

static char	**splitting(
	char const	*s,
	char		**str_array,
	char const	c)
{
	int	i;
	int	j;
	int	w_len;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		w_len = get_len(&s[i], c);
		str_array[j] = ft_substr(s, i, w_len);
		if (!str_array[j])
			return (handle_error(str_array, j));
		j++;
		i = w_len + i;
	}
	str_array[j] = NULL;
	return (str_array);
}

char	**ft_split(char const *s, char c)
{
	char	**str_array;
	int		w_count;

	if (!s)
		return (NULL);
	w_count = word_count(s, c);
	str_array = (char **)malloc(sizeof(char *) * (w_count + 1));
	if (!str_array)
		return (NULL);
	if (s[0] == '\0')
	{
		str_array[0] = NULL;
		return (str_array);
	}
	if (c == '\0')
	{
		str_array[0] = ft_strdup(s);
		if (!str_array[0])
			return (handle_error(str_array, 0));
		str_array[1] = NULL;
		return (str_array);
	}
	return (splitting(s, str_array, c));
}
