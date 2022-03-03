/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:46:48 by bducrocq          #+#    #+#             */
/*   Updated: 2022/03/03 17:14:46 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
// #include "includes/libft.h"
//TODO: passer la reception de la taille  malloc et du pid client en int
//TODO: 
//TODO: --envoyer taille str depuis client avec strlen formatter en 10*8 bit
//TODO: --prevoir envoi du pid client

static t_utils	g_tu;

void sig_handler1()
{
	g_tu.str[g_tu.i] = '0';
	g_tu.i += 1;
	if (g_tu.i == 8)
	{
		g_tu.str[g_tu.i] = '\0';
		g_tu.bin = BINARY_OK_FOR_CHAR;
		//g_tu.progress = FINISH;
	}
}
//
void sig_handler2()
{
	g_tu.str[g_tu.i] = '1';
	g_tu.i += 1;
	if (g_tu.i == 8)
		{
			g_tu.str[g_tu.i] = '\0'; //FIXME: ICI 
			//g_tu.bin = BINARY_OK_FOR_CHAR;
			g_tu.bin = BINARY_OK_FOR_CHAR;
		}
}
// TODO: TODO: TODO:
void	receive_first_parameters()
{	
	g_tu.c = ft_btoi(g_tu.str);
	g_tu.tmpsize[g_tu.y] = g_tu.c;
	//ft_putchar_fd(g_tu.c, 1);
	g_tu.bin = BINARY_WAIT;
	g_tu.i = 0;
	if(g_tu.y == 9 && g_tu.bool == FALSE)
	{
		g_tu.size = ft_atoi(g_tu.tmpsize);
		ft_putnbr_fd(g_tu.size, 1);
		ft_putchar_fd('\n', 1);
		g_tu.bool = TRUE;
		g_tu.y = 0;
	}
	if(g_tu.y == 9 && g_tu.bool == TRUE)
	{
		g_tu.pid = ft_atoi(g_tu.tmpsize);
		ft_putnbr_fd(g_tu.pid, 1);
		ft_putchar_fd('\n', 1);
		g_tu.progress =  START_RECEIVE_MSG;
		g_tu.y = 0;
		return;
	}
		g_tu.y++;
}
int	main()
{
	int		i;
	int		size;
	
	size = 9;
	g_tu.str = ft_calloc(sizeof(char), size);
	g_tu.progress = STEP_PARAMETER;
	g_tu.i = 0;
	g_tu.y = 0;
	printf("server PID: %d\n", getpid());
	//ft_bzero(g_tu.str, size - 1);
	signal(SIGUSR1, sig_handler1);
	signal(SIGUSR2, sig_handler2);

	while(1)
	{
		pause();
		if (g_tu.bin == BINARY_OK_FOR_CHAR && g_tu.progress == STEP_PARAMETER)
			receive_first_parameters();
		if (g_tu.progress == START_RECEIVE_MSG && g_tu.bin == BINARY_OK_FOR_CHAR)
		{
			
			//ft_putstr_fd(g_tu.str, 1);
			g_tu.c = ft_btoi(g_tu.str);
			ft_putchar_fd(g_tu.c, 1);
			g_tu.bin = BINARY_WAIT;
			g_tu.i = 0;
		}
		//printf("%d\n", tu.bool);
	}
	return (0);
}

