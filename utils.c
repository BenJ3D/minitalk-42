/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:44:26 by bducrocq          #+#    #+#             */
/*   Updated: 2022/03/13 18:09:43 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

/**
 * @brief displays size message and pid client
 * 
 * @param pto 
 */
void	displays_message_info(t_tools *pto)
{
	ft_putstr_fd("\n\nReceiving ", 1);
	ft_putnbr_fd(pto->size, 1);
	if (pto->size == 1)
		ft_putstr_fd(" character from client pid ", 1);
	else
		ft_putstr_fd(" characters from client (pid ", 1);
	ft_putnbr_fd(pto->pid, 1);
	ft_putstr_fd(") :\n", 1);
}

/**
 * @brief pass char to binary string
 * 
 * @param c 
 * @return char* 
 */
char	*ft_atob(char c)
{
	int	i;
	int	base;
	char *str;

	str = malloc(sizeof(char) * 9);
	if(!str)
		return (NULL);
	str[8] = '\0';
	base = 128;
	i = 0;
	while (base >= 1)
	{
		if((c / base) == 1)
		{
			str[i] = '1';
			c = c - base;
		}
		else 
			str[i] = '0';
		i++;	
		if (base == 1)
			break;
		base = base / 2;
	}
	return(str);
}

/**
 * @brief Convert a "binary string" to char
 * 
 * @param str 
 * @return int 
 */
int	ft_btoi(char *str)
{
	int		i;
	int		base;
	char	ichar;

	i = 0;
	base = 128;
	while (i < 8)
	{
		if (str[i] == '1')
			ichar += base;
		base = base / 2;
		i++;
	}
	return (ichar);
}
