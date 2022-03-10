/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:05:16 by bducrocq          #+#    #+#             */
/*   Updated: 2022/03/10 16:12:33 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
static t_utils	tu;
//TODO: afficher le nombre de char sent
//TODO: mettre a la norme

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

void sig_handler1(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_putstr_fd("Message bien reçu\n", 1);
		kill(getpid(), SIGQUIT);
	}
}

int	main(int ac, char **av)
{
	int		pidserv;
	tu.bool = 0;
	
	//printf("%d\n", getpid());
	pidserv = atoi(av[1]);
	tu.str = ft_imax_to_str(ft_strlen(av[2]), 10);
	ft_sendbin(tu.str, pidserv, 400); // envoi taille message a malloc
	//ft_sendbin("\n", pidserv, 0);
	free(tu.str);
	tu.str = ft_imax_to_str((int)getpid(), 10);
	ft_sendbin(tu.str, pidserv, 400); //envoi pid client
	free(tu.str);
	//ft_sendbin("\n", pidserv, 0);
	ft_sendbin(av[2], pidserv, 80); //envoi du message
	//ft_sendbin("\n", pidserv, 0);
	signal(SIGUSR1, sig_handler1);
	while(1)
	{
		pause();
	}
	//ft_sendbin("FIN DE MESSAGE", pidserv, 0);
	//ft_sendbin("\n", pidserv, 0);
	free(tu.str);
	return (0);
}