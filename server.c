/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:46:48 by bducrocq          #+#    #+#             */
/*   Updated: 2022/02/26 01:07:48 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
#include "includes/libft.h"

int	bool;


void sig_handler1()
{
	bool = 0;
}

void sig_handler2()
{
	bool = 1;
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
	printf("server PID: %d\n", getpid());
	
	signal(SIGUSR1, sig_handler1);
	signal(SIGUSR2, sig_handler2);


	while(1)
	{
		pause();
		printf("%d\n", bool);
	}
	printf("Finish\n");
	free(tmp);
	return (0);
}