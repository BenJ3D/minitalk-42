/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:46:48 by bducrocq          #+#    #+#             */
/*   Updated: 2022/03/14 17:52:43 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
t_serv	*g_ts;

/**
 * @brief Filled str to form a binary string.
 * When the 8 bits are written, the char is ready.
 * Use ft_btoi function to convert
 * @param signal 
 */
void sig_handler(int signal)
{
	if (signal == SIGUSR1)
		g_ts->str[g_ts->i] = '0'; 
	if (signal == SIGUSR2)
		g_ts->str[g_ts->i] = '1';
	g_ts->i += 1;
	if (g_ts->i == 8)
	{
		g_ts->str[g_ts->i] = '\0';
		g_ts->bin = BINARY_OK_FOR_CHAR; 
	}
}

/**
 * @brief processes the first 20 bits received
 * to determine the message size and the client pid.
 * 
 * @param pto tools struct pointer
 */
void	receive_first_parameters(t_tools *pto)
{	
	pto->c = ft_btoi(g_ts->str);
	pto->tmpsize[pto->y] = pto->c;
	g_ts->bin = BINARY_WAIT;
	g_ts->i = 0;
	if(pto->y == 9 && pto->bool == FALSE)
	{
		pto->size = ft_atoi(pto->tmpsize);
		pto->bool = TRUE;
		pto->y = 0;
		return;
	}
	if(pto->y == 9 && pto->bool == TRUE)
	{
		pto->pid = ft_atoi(pto->tmpsize);
		// ft_putnbr_fd(pto->pid, 1); // affiche le pid client
		 //ft_putchar_fd('\n', 1);
		pto->progress =  GO_RECEIVE_MSG;
		pto->y = 0;
		displays_message_info(pto);
		return;
	}
		pto->y++;
}

/**
 * @brief 
 * 
 * @param ptr 
 */
int	initialize_var(t_tools	*ptr)
{
	g_ts->str = ft_calloc(sizeof(char), 9);
	if(!(g_ts->str))
		return(0);
	g_ts->i = 0;
	ptr->progress = WAIT_PARAMETER;
	ptr->y = 0;
	return(1);
}

/**
 * @brief Convert the binary string to int to fill the message variable.
 * Once the message is complete, displays the message
 * then free() the variable and send a signal to the client 
 * @param pto 
 */
void	write_message(t_tools	*pto)
{
	pto->c = ft_btoi(g_ts->str);
	pto->msg[pto->y] = pto->c;
	g_ts->bin = BINARY_WAIT;
	g_ts->i = 0;
	pto->y++;
	if (pto->y == pto->size)
	{
		ft_putstr_fd(pto->msg, 1);
		free(pto->msg);
		pto->progress = WAIT_PARAMETER; //TODO:
		g_ts->bin = BINARY_WAIT;		   //TODO:
		// pto->progress = GO_RECEIVE_MSG; //FIXME: attention debug
		// g_ts->bin = BINARY_OK_FOR_CHAR; //FIXME:
		pto->y = 0;
	}
}

int	main()
{
	t_tools	to;
	t_serv	ts;
	t_tools	*pto;

	g_ts = &ts;
	pto = &to;

	if(initialize_var(pto) == 0)
		return(0);
	printf("server PID: %d\n", getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while(1)
	{
		pause();
		if (pto->progress == WAIT_PARAMETER && g_ts->bin == BINARY_OK_FOR_CHAR)
			receive_first_parameters(pto);
		if (pto->progress == GO_RECEIVE_MSG && pto->bool == TRUE)
		{
			pto->msg = ft_calloc(pto->size, sizeof(char));
			pto->y = 0;
			pto->bool = FALSE;
		}
		if (pto->progress == GO_RECEIVE_MSG && g_ts->bin == BINARY_OK_FOR_CHAR)
			write_message(pto);
	}
	return (0);
}
