/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: iazaitce <iazaitce@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/13 16:28:46 by iazaitce      #+#    #+#                 */
/*   Updated: 2025/11/24 14:06:47 by iazaitce      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		find_newline(char *line);
size_t	ft_strlen(const char *str);
char	*read_error(char *to_free);
void	offset(char *to_store, int find_nl);

#endif