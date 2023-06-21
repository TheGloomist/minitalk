/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 16:02:24 by izaitcev      #+#    #+#                 */
/*   Updated: 2023/05/31 17:18:18 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/include/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <limits.h>

bool	g_is_validated;

int	mini_atoi(const char *str)
{
	int			i;
	long int	conv;

	i = 0;
	conv = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		conv = (conv * 10) + (str[i] - '0');
		if (conv > INT_MAX || conv < INT_MIN)
			break ;
		i++;
	}
	if (str[i] != '\0' || i == 0)
	{
		write(2, "Please provide valid PID\n", 26);
		exit (1);
	}
	return ((int)conv);
}

void	handle_client_sig(int sig)
{
	(void) sig;
	g_is_validated = true;
}

bool	wait_for_stuff(void)
{
	int	times_slept;

	times_slept = 0;
	while (!g_is_validated)
	{
		usleep(50);
		times_slept++;
		if (times_slept > 50)
			return (false);
	}
	g_is_validated = false;
	return (true);
}

int	send_byte(char byte, int pid)
{
	int	i;
	int	return_check;

	i = 7;
	(void) byte;
	while (i >= 0)
	{
		if (((byte >> i) & 1) == 0)
			return_check = kill(pid, SIGUSR1);
		else
			return_check = kill(pid, SIGUSR2);
		if (return_check == -1)
		{
			write(2, "Failed to send signal to the server\n", 37);
			return (1);
		}
		if (wait_for_stuff() == false)
		{
			write (2, "Server timed out\n", 18);
			return (1);
		}
		i--;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
	{
		write(2, "Provide exactly 3 arguments\n", 29);
		return (1);
	}
	g_is_validated = false;
	signal(SIGUSR1, &handle_client_sig);
	pid = mini_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		if (send_byte(argv[2][i], pid) == 1)
			return (1);
		i++;
	}
	if (send_byte('\n', pid) == 1)
		return (1);
	return (0);
}
