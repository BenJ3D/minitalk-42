/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:05:16 by bducrocq          #+#    #+#             */
/*   Updated: 2022/03/02 17:55:42 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
static t_utils	tu;

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
 * @brief formate un int en str a 10 chiffres (ex : 0000004242)
 * avant envoi en binaire (!free str!)
 * @param str (adresse *str non maloc )
 * @param len (int a formatter)
 */
void	ft_imax_to_str()
{
	tu.str = ft_calloc(10, sizeof(char));
	tu.y = 9;
	ft_memset(tu.str, '0', 10);
	tu.tmp = ft_itoa(tu.size);
	tu.i = ft_strlen(tu.tmp) - 1;
	 while (tu.i >= 0)
		tu.str[tu.y--] = tu.tmp[tu.i--];
	//printf("str = %s \n size = %i", tu.str, tu.size);
	free(tu.tmp);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*msgsize;

	tu.size = ft_strlen(av[2]);
	pid = atoi(av[1]);
	
	ft_imax_to_str();
	ft_sendbin(tu.str, pid, 0);
	ft_sendbin("\n", pid, 0);
	ft_sendbin(av[2], pid, 0);
	ft_sendbin("\n", pid, 0);
	ft_sendbin("FIN DE MESSAGE", pid, 0);
	ft_sendbin("\n", pid, 0);
	free(tu.str);
	return (0);
}