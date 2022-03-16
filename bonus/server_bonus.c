/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:46:48 by bducrocq          #+#    #+#             */
/*   Updated: 2022/03/15 18:00:02 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk_bonus.h"

/**
 * @brief Filled str to form a binary string.
 * When the 8 bits are written, the char is ready.
 * Use ft_btoi function to convert
 * @param signal 
 */
void	sig_handler(int signal)
{
	if (signal == SIGUSR1)
		g_serv->str[g_serv->i] = '0';
	if (signal == SIGUSR2)
		g_serv->str[g_serv->i] = '1';
	g_serv->i += 1;
	if (g_serv->i == 8)
	{
		g_serv->str[g_serv->i] = '\0';
		g_serv->bin = BIN_OK_FOR_CHAR;
	}
}

/**
 * @brief processes the first 20 bits received
 * to determine the message size and the client pid.
 * 
 * @param ptools tools struct pointer
 */
void	receive_first_parameters(t_tools *ptools)
{	
	ptools->c = ft_btoi(g_serv->str);
	ptools->tmpsize[ptools->y] = ptools->c;
	g_serv->bin = BINARY_WAIT;
	g_serv->i = 0;
	if (ptools->y == 9 && ptools->bool == FALSE)
	{
		ptools->size = ft_atoi(ptools->tmpsize);
		ptools->bool = TRUE;
		ptools->y = 0;
		return ;
	}
	if (ptools->y == 9 && ptools->bool == TRUE)
	{
		ptools->pid = ft_atoi(ptools->tmpsize);
		ptools->progress = GO_RECEIVE_MSG;
		ptools->y = 0;
		displays_message_info(ptools);
		return ;
	}
		ptools->y++;
}

/**
 * @brief 
 * 
 * @param ptr 
 */
int	initialize_var(t_tools	*ptr)
{
	static t_serv	ts;

	g_serv = &ts;
	g_serv->str = ft_calloc(sizeof(char), 9);
	if (!(g_serv->str))
		return (0);
	g_serv->i = 0;
	ptr->progress = WAIT_PARAMETER;
	ptr->y = 0;
	return (1);
}

/**
 * @brief Convert the binary string to int to fill the message variable.
 * Once the message is complete, displays the message
 * then free() the variable and send a signal to the client 
 * @param ptools 
 */
void	write_message(t_tools	*ptools)
{
	ptools->c = ft_btoi(g_serv->str);
	ptools->msg[ptools->y] = ptools->c;
	g_serv->bin = BINARY_WAIT;
	g_serv->i = 0;
	ptools->y++;
	if (ptools->y == ptools->size)
	{
		ptools->msg[ptools->y] = '\0';
		ft_putstr_fd(ptools->msg, 1);
		free(ptools->msg);
		ft_putstr_fd("\n\n", 1);
		ptools->progress = WAIT_PARAMETER;
		g_serv->bin = BINARY_WAIT;
		ptools->y = 0;
		usleep(500);
		kill(ptools->pid, SIGUSR1);
	}
}

int	main(void)
{
	t_tools	tools;
	t_tools	*ptls;

	ptls = &tools;
	if (initialize_var(ptls) == 0)
		return (0);
	printf("server PID: %d\n", getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
	{
		pause();
		if (ptls->progress == WAIT_PARAMETER && g_serv->bin == BIN_OK_FOR_CHAR)
			receive_first_parameters(ptls);
		if (ptls->progress == GO_RECEIVE_MSG && ptls->bool == TRUE)
		{
			ptls->msg = ft_calloc(ptls->size + 1, sizeof(char));
			ptls->y = 0;
			ptls->bool = FALSE;
		}
		if (ptls->progress == GO_RECEIVE_MSG && g_serv->bin == BIN_OK_FOR_CHAR)
			write_message(ptls);
	}
	return (0);
}
