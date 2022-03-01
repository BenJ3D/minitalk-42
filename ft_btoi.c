/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 03:39:19 by bducrocq          #+#    #+#             */
/*   Updated: 2022/03/01 12:27:14 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

char	ft_btoi2(char *str)
{
	int		i;
	int		base;
	char	ichar;

	i = 0;
	base = 128;
	while(i < 8)
	{
		if (str[i] == '1')
			ichar += base;
		base = base / 2;
		i++;
	}
	return (ichar);
}

	int main(int ac, char **av)
	{
		int		i;
		int		y;
		char	*c;
		char	*tmp;

		tmp = malloc(sizeof(char) * (ft_strlen(av[1]) + 1));
		i = 0;
		y = 0;
		char	str[] = "coucou";
		while (av[1][i])
		{
			c = ft_atob(av[1][i++]);
			printf("\n%s", c);
			printf("%c", ft_btoi2(c));
			tmp[y] = ft_btoi2(c);
			y++;
			free(c);
		}
		tmp[y] = '\0';
		printf("\nresult = %s", tmp);
		free(tmp);
		return (0);
	}