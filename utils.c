/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:44:26 by bducrocq          #+#    #+#             */
/*   Updated: 2022/02/26 00:42:54 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

/**
 * @brief pass char to binary
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
	str[i] = '\0';
	return(str);
}


// int main(int argc, char **argv)
// {	
// 	char *str;

// 	str = ft_atob(argv[1][0]);
// 	printf("%s", str);
// 	free(str);
// 	return(0);
// }