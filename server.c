/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:46:48 by bducrocq          #+#    #+#             */
/*   Updated: 2022/02/26 01:44:28 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
#include "includes/libft.h"


void sig_handler1()
{
	tu.bool = 0;
}

void sig_handler2()
{
	tu.bool = 1;
	tu.progress = FINISH;
}

int	main()
{
	int		i;
	int		size;
	
	size = 40;
	// tu.str = ft_calloc(sizeof(char), size);
	// if (!tu.str)
	// 	return(0);
	i = 0;
	printf("server PID: %d\n", getpid());
	
	signal(SIGUSR1, sig_handler1);
	signal(SIGUSR2, sig_handler2);

	while(1)
	{
		pause();
		if (tu.progress == FINISH)
			break;
		printf("%d\n", tu.bool);
	}
	printf("FINISH !!\n");
	return (0);
}