/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:46:48 by bducrocq          #+#    #+#             */
/*   Updated: 2022/02/25 16:54:32 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

// void	sigusr_process()

void sig_handler1()
{
	ft_putstr_fd("handler1", 1);
}

void sig_handler2()
{
	ft_putstr_fd("handler2", 1);
}

int	main()
{
	int	i;
	int	size;
	char	*tmp;
	
	size = 40;
	tmp = ft_calloc(sizeof(char), size);
	if (!tmp)
		return(0);
	i = 0;
	printf("server PID : %d\n", getpid());
	
	signal(SIGUSR1, sig_handler1);
	signal(SIGUSR2, sig_handler2);

	while(1)
	{
		pause();
	}
	printf("Finish\n");
	free(tmp);
	return (0);
}