/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbayrakt <tbayrakt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:30:40 by tanselbayra       #+#    #+#             */
/*   Updated: 2024/10/08 10:48:46 by tbayrakt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_return_power(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}

char	*char_append(char const *s1, char const letter)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	tab[j++] = letter;
	tab[j] = 0;
	free((void *)(s1));
	return (tab);
}

void	signal_handler(int signum)
{
	static int	counter = 0;
	static int	result = 0;
	static char	*final;

	if (!final)
		final = ft_strdup("");
	if (signum == SIGUSR1)
		result = result + 0;
	else if (signum == SIGUSR2)
		result = result + (1 * ft_return_power(2, 7 - counter));
	counter++;
	if (counter == 8)
	{
		final = char_append(final, result);
		if (result == '\0')
		{
			ft_printf("%s\n", final);
			final = NULL;
		}
		counter = 0;
		result = 0;
	}
}

int	main(void)
{
	struct sigaction	signal_action;
	int					pid;

	pid = getpid();
	ft_printf("Welcome to minitalk server:\n");
	ft_printf("---------------------------\n");
	ft_printf("Server's PID: %i\n", pid);
	signal_action.sa_handler = signal_handler;
	signal_action.sa_flags = 0;
	sigaction(SIGUSR1, &signal_action, NULL);
	sigaction(SIGUSR2, &signal_action, NULL);
	while (1)
		usleep(50);
}
