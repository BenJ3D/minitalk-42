/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:46:48 by bducrocq          #+#    #+#             */
/*   Updated: 2022/03/10 11:17:26 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
// #include "includes/libft.h"

static t_utils	tu;

void sig_handler_old(int	signal)
{
	if (signal == SIGUSR1)
		tu.str[tu.i] = '0';
	if (signal == SIGUSR2)
		tu.str[tu.i] = '1';
	tu.i += 1;
	if (tu.i == 8)
	{
		tu.str[tu.i] = '\0';
		tu.bin = BINARY_OK_FOR_CHAR;
		//tu.progress = FINISH;
	}
}

// TODO: TODO: TODO: suuprimer la variable global
// TODO: mettre a la norme
void	receive_first_parameters(void)
{	
	tu.c = ft_btoi(tu.str);
	tu.tmpsize[tu.y] = tu.c;
	//ft_putchar_fd(tu.c, 1);
	tu.bin = BINARY_WAIT;
	tu.i = 0;
	if(tu.y == 9 && tu.bool == FALSE)
	{
		tu.size = ft_atoi(tu.tmpsize);
		//  ft_putchar_fd('\n', 1);
		//  ft_putnbr_fd(tu.size, 1); // affiche la taille du message a recevoir
		//  ft_putchar_fd('\n', 1);
		tu.bool = TRUE;
		tu.y = 0;
		return;
	}
	if(tu.y == 9 && tu.bool == TRUE)
	{
		tu.pid = ft_atoi(tu.tmpsize);
		ft_putnbr_fd(tu.pid, 1); // affiche le pid client
		ft_putchar_fd('\n', 1);
		tu.progress =  START_RECEIVE_MSG;
		tu.y = 0;
		return;
	}
		tu.y++;
}
int	main()
{
	int		i;
	int		size;
	
	size = 9;
	tu.str = ft_calloc(sizeof(char), size);
	tu.progress = STEP_PARAMETER;
	tu.i = 0;
	tu.y = 0;
	printf("server PID: %d\n", getpid());
	//ft_bzero(tu.str, size - 1);
	signal(SIGUSR1, sig_handler_old);
	signal(SIGUSR2, sig_handler_old);
	while(1)
	{
		pause();
		if (tu.bin == BINARY_OK_FOR_CHAR && tu.progress == STEP_PARAMETER)
			receive_first_parameters();
		if (tu.progress == START_RECEIVE_MSG && tu.bool == TRUE)
		{
			tu.msg = ft_calloc(tu.size, sizeof(char));
			tu.y = 0;
			tu.bool = FALSE;
		}
		if (tu.progress == START_RECEIVE_MSG && tu.bin == BINARY_OK_FOR_CHAR)
		{
			//ft_putstr_fd(tu.str, 1); // affiche les binaires des chars
			tu.c = ft_btoi(tu.str); // converti les 8 binaire dans str en int dans tu.c
			//ft_putchar_fd(tu.c, 1); // affiche les char un a un FIXME:
			tu.msg[tu.y] = tu.c;
			tu.bin = BINARY_WAIT;
			tu.i = 0;
			tu.y++;
			//ft_putnbr_fd(tu.y, 1);
			if (tu.y == tu.size)
			{
				tu.msg[tu.y] = '\0';
				ft_putstr_fd(tu.msg, 1);
				free(tu.msg);
				tu.progress = STEP_PARAMETER;
				tu.bin = BINARY_WAIT;
				kill(tu.pid, SIGUSR1);
				tu.x = 0;
				tu.y = 0;
			}
		}
		//printf("%d\n", tu.bool);
	}
	return (0);
}

