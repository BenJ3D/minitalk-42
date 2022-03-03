/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:05:16 by bducrocq          #+#    #+#             */
/*   Updated: 2022/03/02 20:49:32 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
static t_utils	tu;
//TODO: mettrre en pause le client pour ecouter les messages en retour et stopper le process
void	ft_sendbin(char *str, int pid, int i)
{
	char	*tmp;
	int		j;
	
	//tmp = malloc(sizeof(char) * 9);
	// if (!tmp)
	// 	return;
	//tmp[8] = '\0';
	i = 0;
	while (str[i])
	{
		// if (str[i] < 0 || str[i] > 127)
		// 	{tmp = ft_atob('?'); printf("\ntmp debug %s\n", tmp);} //FIXME:
		// else
		tmp = ft_atob(str[i]);
		j = 0;
		while(tmp[j])
		{
			if (tmp[j] == '0')
				kill(pid, SIGUSR1); 
			if (tmp[j] == '1')
				kill(pid, SIGUSR2);
			usleep(100);
			j++;
		}
		i++;
	}
	free(tmp);
}

/**
 * @brief formate un int en str a $count chiffres 
 * (ex int = 4242 count = 10 return str : 0000004242)
 * (!free str!)
 * @param size 	l'int a formater en str
 * @param count 
 * @return char* 
 */
char	*ft_imax_to_str(int size, int count)
{
	t_utils	to;
	
	to.str = ft_calloc(count, sizeof(char));
	to.y = count - 1;
	ft_memset(to.str, '0', count);
	to.tmp = ft_itoa(size);
	to.i = ft_strlen(to.tmp) - 1;
	 while (to.i >= 0)
		to.str[to.y--] = to.tmp[to.i--];
	//printf("str = %s \n size = %i", to.str, size);
	free(to.tmp);
	return(to.str);
}

void sig_handler1()
{
	printf("Message bien reçu");
	tu.bool = 1;
}

int	main(int ac, char **av)
{
	int		pidserv;
	tu.bool = 0;

	pidserv = atoi(av[1]);
	tu.str = ft_imax_to_str(ft_strlen(av[2]), 10);
	//printf("\nSTR !!! = %s\n", tu.str);
	ft_sendbin(tu.str, pidserv, 0);
	ft_sendbin("\n", pidserv, 0);
	free(tu.str);
	tu.str = ft_imax_to_str((int)getpid(), 10);
	ft_sendbin(tu.str, pidserv, 0);
	ft_sendbin("\n", pidserv, 0);
	ft_sendbin(av[2], pidserv, 0);
	ft_sendbin("\n", pidserv, 0);
	signal(SIGUSR1, sig_handler1);
	while(1)
	{
		sleep(1);
		//if (tu.bool == 1)
	printf("Message bien reçu");
			break;
	}
	ft_sendbin("FIN DE MESSAGE", pidserv, 0);
	ft_sendbin("\n", pidserv, 0);
	free(tu.str);
	return (0);
}