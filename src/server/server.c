/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: iazaitce <iazaitce@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/05/05 18:46:38 by iazaitce      #+#    #+#                 */
/*   Updated: 2026/05/18 20:32:07 by iazaitce      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/include/libft.h"
#include <unistd.h>
#include <signal.h>

void	handle_signal(int sig, siginfo_t *info, void *garbo)
{
	static char	byte = '\0';
	static int	call_counter = 0;

	(void) garbo;
	call_counter++;
	byte = (byte << 1) | (sig == SIGUSR2);
	if (call_counter == 8)
	{
		write(1, &byte, 1);
		byte = '\0';
		call_counter = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		byte = '\0';
		call_counter = 0;
		write(2, "Confirmation signal failure\n", 29);
	}
}

// sigaction is used because it allows settings for the signal handling
// SIGUSR1 = 0 bit
// SIGUSR2 = 1 bit
int	main(void)
{
	struct sigaction	sig;

	ft_printf("PID: %i\n", getpid());
	sig.sa_sigaction = &handle_signal;
	sig.sa_flags = SA_NODEFER | SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		sleep(1);
}
