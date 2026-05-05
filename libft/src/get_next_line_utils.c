/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: iazaitce <iazaitce@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/13 16:28:43 by iazaitce      #+#    #+#                 */
/*   Updated: 2025/11/21 17:54:17 by iazaitce      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	ret_val;

	ret_val = 0;
	if (!str)
		return (ret_val);
	while (str[ret_val] != '\0')
		ret_val++;
	return (ret_val);
}

char	*read_error(char *to_free)
{
	free(to_free);
	return (NULL);
}

void	offset(char *to_store, int nl_pos)
{
	int	i;

	i = 0;
	while (to_store[nl_pos + i] != '\0')
	{
		to_store[i] = to_store[nl_pos + i];
		i++;
	}
	while (to_store[i] != '\0')
	{
		to_store[i] = '\0';
		i++;
	}
}
