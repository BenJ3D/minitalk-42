/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:46:48 by bducrocq          #+#    #+#             */
/*   Updated: 2022/03/09 20:27:26 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
// #include "includes/libft.h"

static t_utils	g_tu;

void sig_handler_old(int	signal)
{
	if (signal == SIGUSR1)
		g_tu.str[g_tu.i] = '0';
	if (signal == SIGUSR2)
		g_tu.str[g_tu.i] = '1';
	g_tu.i += 1;
	if (g_tu.i == 8)
	{
		g_tu.str[g_tu.i] = '\0';
		g_tu.bin = BINARY_OK_FOR_CHAR;
		//g_tu.progress = FINISH;
	}
}

// TODO: TODO: TODO: suuprimer la variable global
// TODO: mettre a la norme
void	receive_first_parameters(void)
{	
	g_tu.c = ft_btoi(g_tu.str);
	g_tu.tmpsize[g_tu.y] = g_tu.c;
	//ft_putchar_fd(g_tu.c, 1);
	g_tu.bin = BINARY_WAIT;
	g_tu.i = 0;
	if(g_tu.y == 9 && g_tu.bool == FALSE)
	{
		g_tu.size = ft_atoi(g_tu.tmpsize);
		//  ft_putchar_fd('\n', 1);
		//  ft_putnbr_fd(g_tu.size, 1); // affiche la taille du message a recevoir
		//  ft_putchar_fd('\n', 1);
		g_tu.bool = TRUE;
		g_tu.y = 0;
		return;
	}
	if(g_tu.y == 9 && g_tu.bool == TRUE)
	{
		g_tu.pid = ft_atoi(g_tu.tmpsize);
		ft_putnbr_fd(g_tu.pid, 1); // affiche le pid client
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
	signal(SIGUSR1, sig_handler_old);
	signal(SIGUSR2, sig_handler_old);
	while(1)
	{
		pause();
		if (g_tu.bin == BINARY_OK_FOR_CHAR && g_tu.progress == STEP_PARAMETER)
			receive_first_parameters();
		if (g_tu.progress == START_RECEIVE_MSG && g_tu.bool == TRUE)
		{
			g_tu.msg = ft_calloc(g_tu.size, sizeof(char));
			g_tu.y = 0;
			g_tu.bool = FALSE;
		}
		if (g_tu.progress == START_RECEIVE_MSG && g_tu.bin == BINARY_OK_FOR_CHAR)
		{
			//ft_putstr_fd(g_tu.str, 1); // affiche les binaires des chars
			g_tu.c = ft_btoi(g_tu.str); // converti les 8 binaire dans str en int dans g_tu.c
			//ft_putchar_fd(g_tu.c, 1); // affiche les char un a un FIXME:
			g_tu.msg[g_tu.y] = g_tu.c;
			g_tu.bin = BINARY_WAIT;
			g_tu.i = 0;
			g_tu.y++;
			//ft_putnbr_fd(g_tu.y, 1);
			if (g_tu.y == g_tu.size)
			{
				g_tu.msg[g_tu.y] = '\0';
				ft_putstr_fd(g_tu.msg, 1);
				free(g_tu.msg);
				g_tu.progress = STEP_PARAMETER;
				g_tu.bin = BINARY_WAIT;
				kill(g_tu.pid, SIGUSR1);
				g_tu.x = 0;
				g_tu.y = 0;
			}
		}
		//printf("%d\n", tu.bool);
	}
	return (0);
}

