/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 03:39:19 by bducrocq          #+#    #+#             */
/*   Updated: 2022/03/01 04:03:12 by bducrocq         ###   ########.fr       */
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

	int main()
	{
		int		i;
		int		y;
		char	*c;
		char	*tmp;

		tmp = malloc(sizeof(char) * 7);
		i = 0;
		y = 0;
		char	str[] = "coucou";
		while (str[i])
		{
			c = ft_atob(str[i++]);
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