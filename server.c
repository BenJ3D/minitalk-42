/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:46:48 by bducrocq          #+#    #+#             */
/*   Updated: 2022/03/12 16:48:14 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
t_serv	g_ts;

void sig_handler_old(int signal)
{
	if (signal == SIGUSR1)
		g_ts.str[g_ts.i] = '0';
	if (signal == SIGUSR2)
		g_ts.str[g_ts.i] = '1';
	g_ts.i += 1;
	if (g_ts.i == 8)
	{
		g_ts.str[g_ts.i] = '\0';
		g_ts.bin = BINARY_OK_FOR_CHAR;
	}
}

// TODO: mettre a la norme
void	receive_first_parameters(t_tools *ptls)
{	
	ptls->c = ft_btoi(g_ts.str);
	ptls->tmpsize[ptls->y] = ptls->c;
	g_ts.bin = BINARY_WAIT;
	g_ts.i = 0;
	if(ptls->y == 9 && ptls->bool == FALSE)
	{
		ptls->size = ft_atoi(ptls->tmpsize);
		 ft_putchar_fd('\n', 1);
		 ft_putnbr_fd(ptls->size, 1); // affiche la taille du message a recevoir
		 ft_putchar_fd('\n', 1);
		ptls->bool = TRUE;
		ptls->y = 0;
		return;
	}
	if(ptls->y == 9 && ptls->bool == TRUE)
	{
		ptls->pid = ft_atoi(ptls->tmpsize);
		ft_putnbr_fd(ptls->pid, 1); // affiche le pid client
		ft_putchar_fd('\n', 1);
		ptls->progress =  GO_RECEIVE_MSG;
		ptls->y = 0;
		return;
	}
		ptls->y++;
}

void	initialize_var(t_tools	*ptr)
{
	g_ts.str = ft_calloc(sizeof(char), 9);
	g_ts.i = 0;
	ptr->progress = WAIT_PARAMETER;
	ptr->y = 0;
}
int	main()
{
	t_tools	to;
	t_tools	*ptls;
	
	ptls = &to;
	initialize_var(ptls);
	printf("server PID: %d\n", getpid());
	signal(SIGUSR1, sig_handler_old);
	signal(SIGUSR2, sig_handler_old);
	while(1)
	{
		pause();
		if (g_ts.bin == BINARY_OK_FOR_CHAR && ptls->progress == WAIT_PARAMETER)
			receive_first_parameters(ptls);
		if (ptls->progress == GO_RECEIVE_MSG && ptls->bool == TRUE)
		{
			ptls->msg = ft_calloc(ptls->size, sizeof(char));
			ptls->y = 0;
			ptls->bool = FALSE;
		}
		if (ptls->progress == GO_RECEIVE_MSG && g_ts.bin == BINARY_OK_FOR_CHAR)
		{
			//ft_putstr_fd(g_ts.str, 1); // affiche les binaires des chars
			ptls->c = ft_btoi(g_ts.str); // converti les 8 binaire dans str en int dans ptls->c
			//ft_putchar_fd(ptls->c, 1); // affiche les char un a un FIXME:
			ptls->msg[ptls->y] = ptls->c;
			g_ts.bin = BINARY_WAIT;
			g_ts.i = 0;
			ptls->y++;
			//ft_putnbr_fd(ptls->y, 1);
			if (ptls->y == ptls->size)
			{
				ptls->msg[ptls->y] = '\0';
				ft_putstr_fd(ptls->msg, 1);
				free(ptls->msg);
				ptls->progress = WAIT_PARAMETER;
				g_ts.bin = BINARY_WAIT;
				kill(ptls->pid, SIGUSR1);
				ptls->x = 0;
				ptls->y = 0;
			}
		}
		//printf("%d\n", ptls->bool);
	}
	return (0);
}

