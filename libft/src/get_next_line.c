/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: iazaitce <iazaitce@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/13 16:28:38 by iazaitce      #+#    #+#                 */
/*   Updated: 2025/11/21 17:51:55 by iazaitce      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nl_position(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		return (i + 1);
	else
		return (-1);
}

char	*allocate_line(char *old_line, const char *new_part, int nl)
{
	int		len;
	char	*expanded_line;

	if (nl == -1)
		len = ft_strlen(old_line) + ft_strlen(new_part);
	else
		len = ft_strlen(old_line) + nl;
	if (len == 0)
		return (NULL);
	expanded_line = (char *) malloc(sizeof(char) * (len + 1));
	if (expanded_line == NULL)
		return (NULL);
	return (expanded_line);
}

char	*add_to_line(char *old_line, const char *new_part, int nl)
{
	char	*expanded_line;
	int		i;
	int		j;

	expanded_line = allocate_line(old_line, new_part, nl);
	if (expanded_line)
	{
		i = 0;
		while (old_line && old_line[i] != '\0')
		{
			expanded_line[i] = old_line[i];
			i++;
		}
		j = 0;
		while (new_part[j] != '\0' && j != nl)
		{
			expanded_line[i + j] = new_part[j];
			j++;
		}
		expanded_line[i + j] = '\0';
	}
	free(old_line);
	return (expanded_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	to_store[BUFFER_SIZE + 1];
	int			i;
	int			nl_pos;

	line = NULL;
	nl_pos = -1;
	while (nl_pos == -1)
	{
		if (to_store[0] == '\0')
		{
			i = read(fd, to_store, BUFFER_SIZE);
			if (i == 0)
				break ;
			if (i == -1)
				return (read_error(line));
			to_store[i] = '\0';
		}
		nl_pos = nl_position(to_store);
		line = add_to_line(line, to_store, nl_pos);
		if (line == NULL)
			return (NULL);
		offset(to_store, nl_pos);
	}
	return (line);
}
