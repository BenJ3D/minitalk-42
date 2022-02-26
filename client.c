/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:05:16 by bducrocq          #+#    #+#             */
/*   Updated: 2022/02/26 00:45:49 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

void	ft_sendbin(char *str, int pid, int i)
{
	char	*tmp;
	int		j;
	
	tmp = malloc(sizeof(char) * 9);
	if (!tmp)
		return;
	tmp[8] = '\0';
	i = 0;
	while (str[i])
	{
		tmp = ft_atob(str[i]);
		j = 0;
		while(tmp[j])
		{
			if (tmp[j] == '0')
				kill(pid, SIGUSR1); 
			if (tmp[j] == '1')
				kill(pid, SIGUSR2);
			usleep(1000);
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	pid = atoi(av[1]);
	ft_sendbin(av[2], pid, 0);
	return (0);
}