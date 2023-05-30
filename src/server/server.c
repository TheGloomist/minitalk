/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: izaitcev <izaitcev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 16:02:21 by izaitcev      #+#    #+#                 */
/*   Updated: 2023/05/30 18:05:13 by izaitcev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/include/libft.h"
#include <unistd.h>
#include <signal.h>

void	handle_signal(int sig, siginfo_t *info, void *garbo)
{
	static char byte = '\0';
	static int	times_called = 0;

	(void) garbo;
	times_called++;
	byte = (byte << 1) | (sig == SIGUSR2);
	if (times_called == 8)
	{
		write(1, &byte, 1);
		byte = '\0';
		times_called = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		{
			byte = '\0';
			times_called = 0;
			write(2, "Confirmation signal failure\n", 29);
		}
}

// sigaction is used because it allows settings for the signal handling
// SIGUSR1 = 0 bit
// SIGUSR2 = 1 bit
int	main(void)
{
	struct sigaction sig;
	
	ft_printf("PID: %i\n", getpid());
	sig.sa_sigaction = &handle_signal;
	sig.sa_flags = SA_NODEFER | SA_SIGINFO; // enable flags
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while(1)
		sleep(1);
}