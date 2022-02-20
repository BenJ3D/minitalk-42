/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:38:28 by bducrocq          #+#    #+#             */
/*   Updated: 2022/02/10 23:06:36 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

/**
 * @brief sort my arg p x X
 * 
 * @param nb 
 * @param arg 
 * @param ret counter for total char write
 * @return int
 */
void	ft_sort_arg_hexa(unsigned long long int nb, char arg, int **ret)
{
	if (arg == 'x' || arg == 'X')
	{
		nb = (unsigned int)nb;
		if (!nb)
		{
			**ret += write(1, "0", 1);
			return ;
		}
		ft_print_hexa(nb, arg, &ret);
		return ;
	}
	if (!nb)
	{
		**ret += write(1, "0x0", 3);
		return ;
	}
	ft_print_pointer(nb, &ret);
	return ;
}

/**
 * @brief print pointer
 * 
 * @param nb 
 * @param ret counter for total char write
 */
void	ft_print_pointer(unsigned long long int nb, int ***ret)
{
	char					*base;
	unsigned long long int	res;
	static int				bool = 0;

	if (bool == 0)
	{
		***ret += write(1, "0x", 2);
		bool = 1;
	}
	base = "0123456789abcdef";
	res = nb % 16;
	if (res != 0 || nb != 0)
	{
		nb = nb / 16;
		ft_print_pointer(nb, &*ret);
		ft_putchar_fd(base[res], 1);
		***ret += 1;
	}
	bool = 0;
	return ;
}

void	ft_print_hexa(unsigned long long int nb, char arg, int ***ret)
{
	char					*base;
	unsigned long long int	res;

	if (arg == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	res = nb % 16;
	if (res != 0 || nb != 0)
	{
		nb = nb / 16;
		ft_print_hexa(nb, arg, &*ret);
		ft_putchar_fd(base[res], 1);
		***ret += 1;
	}
}
