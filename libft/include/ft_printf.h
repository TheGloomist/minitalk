/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: iazaitce <iazaitce@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/14 18:16:10 by iazaitce      #+#    #+#                 */
/*   Updated: 2025/11/20 16:36:20 by iazaitce      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_strlen(char *str);
int	print_str(char *str);
int	print_char(int c);
int	print_num(long int n);
int	print_unsigned_dec(unsigned int n);
int	print_lowhex(unsigned long n);
int	print_uphex(unsigned int n);
int	print_pointer(unsigned long n);

#endif