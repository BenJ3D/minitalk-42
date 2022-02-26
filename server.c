/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:46:48 by bducrocq          #+#    #+#             */
/*   Updated: 2022/02/26 03:08:32 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
#include "includes/libft.h"

//TODO: --ecrire bin to ascii dans utils!
//TODO: --envoyer taille str depuis client avec strlen formatter en 10*8 bit
//TODO: --prevoir envoi du pid client


void sig_handler1()
{
	tu.str[tu.i] = '0';
	tu.i += 1;
	if (tu.i == 8)
	{
		tu.str[tu.i] = '\0';
		tu.progress = FINISH;
	}
}

void sig_handler2()
{
	tu.str[tu.i] = '1';
	tu.i += 1;
	if (tu.i == 8)
		{
			tu.str[tu.i] = '\0';
			tu.progress = FINISH;
		}
}

int	main()
{
	int		i;
	int		size;
	
	i = 0;
	// size = 40;
	// tu.str = ft_calloc(sizeof(char), size);
	// if (!tu.str)
	// 	return(0);
	tu.i = 0;
	printf("server PID: %d\n", getpid());
	

	signal(SIGUSR1, sig_handler1);
	signal(SIGUSR2, sig_handler2);

	while(1)
	{
		pause();
		if (tu.progress == FINISH)
		{
			
			printf("%s\n", tu.str);
			printf("%c\n", ft_btoi(tu.str));
			tu.progress = NOT_FINISH;
			tu.i = 0;
		}
		//printf("%d\n", tu.bool);
	}
	printf("FINISH !!\n");
	return (0);
}



// if (tu.i == 7)
// 		{
// 			c = ft_btoi(tu.str);
// 			write(1, c, 1);
// 			tu.i = 0;
// 		}