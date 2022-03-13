/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:05:16 by bducrocq          #+#    #+#             */
/*   Updated: 2022/03/13 17:57:35 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

enum e_bool	msg_ok;

//TODO:	-debugger sinal
/**
 * @brief send message in binary
 * 
 * @param str string to send
 * @param pid pid server
 * @param speed speed usleep sending signal 
 * 	(100 by default, some mac break with less)
 */
void	ft_sendbin(char *str, int pid, int speed)
{
	char	*tmp;
	int		j;
	int		i;
	
	i = 0;
	while (str[i])
	{
		tmp = ft_atob(str[i]);
		j = 0;
		while(tmp[j])
		{
			if (tmp[j] == '0')
				kill(pid, SIGUSR1); 
			if (tmp[j] == '1')
				kill(pid, SIGUSR2);
			usleep(speed);
			j++;
		}
		i++;
	}
	free(tmp);
}

/**
 * @brief int to str with x $count char
 * (ex int = 4242 count = 10 return str : 0000004242)
 * (!free str!)
 * @param size 	l'int a formater en str
 * @param count 
 * @return char* 
 */
char	*ft_imax_to_str(int size, int count)
{
	t_tools	to;
	
	to.str = ft_calloc(count, sizeof(char));
	to.y = count - 1;
	ft_memset(to.str, '0', count);
	to.tmp = ft_itoa(size);
	to.i = ft_strlen(to.tmp) - 1;
	 while (to.i >= 0)
		to.str[to.y--] = to.tmp[to.i--];
	free(to.tmp);
	return(to.str);
}

void signal_handler_client(int signal)
{
	static int	y = 0;
	if (signal == SIGUSR1)
	{
		ft_putstr_fd("The server has received the message\n", 1);
		msg_ok = TRUE;
		kill(getpid(), SIGQUIT);
	}
}

int	main(int ac, char **av)
{
	t_tools	tc;
	t_tools	*ptc;
	int		pidserv;
	
	printf("pid client: %d\n", getpid());
	ptc = &tc;
	ptc->bool = 0;
	msg_ok = FALSE;
	pidserv = ft_atoi(av[1]);
	ptc->str = ft_imax_to_str(ft_strlen(av[2]), 10);
	ft_sendbin(ptc->str, pidserv, 400);
	free(ptc->str);
	ptc->str = ft_imax_to_str((int)getpid(), 10);
	ft_sendbin(ptc->str, pidserv, 400);
	free(ptc->str);
	ft_sendbin(av[2], pidserv, SPEED);
	free(ptc->str);
	signal(SIGUSR1, signal_handler_client);
	while(1)
	{
		pause();
		if (msg_ok == TRUE)
			return(0);
	}
	return (0);
}