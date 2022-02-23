/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:44:26 by bducrocq          #+#    #+#             */
/*   Updated: 2022/02/23 23:51:55 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

char	*ft_atob(char c)
{
	int	i;
	int	base;
	char str[8];

	base = 128;

	i = 0;
	printf("%d %d %d\n", c, (c / 128), (c % 128));
	while (i < 8)
	{
		if((c / base) == 1) // diviser par base qui se divise par 2 a chaque tour
			str[i++] = 1;
		else 
		str[i++] = 0;
			
	}
	return(str);
}


int main()
{

	ft_atob('L');
	return(0);
}