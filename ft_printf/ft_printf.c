/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:24:56 by bducrocq          #+#    #+#             */
/*   Updated: 2022/02/10 22:46:09 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

/*******************************************************\
Une petite description des conversions requises :
• %c imprime un seul caractère.
• %s imprime une chaîne de caractères.
• %p L’argument de pointeur void * est imprimé en hexadécimal.
• %d imprime un nombre décimal (base 10).
• %i imprime un entier en base 10.
• %u imprime un nombre décimal non signé (base 10).
• %x imprime un nombre en hexadécimal (base 16).
• %X imprime un nombre en hexadécimal en majuscule (base 16).
• %% imprime un signe de pourcentage..
\*******************************************************/

void	check_arg(va_list ap, const char fmt, int *ret, int *i)
{
	if (fmt == 's')
		*ret += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (fmt == 'c')
		*ret += ft_putchar_fd(va_arg(ap, int), 1);
	else if (fmt == 'd' || fmt == 'i')
		*ret += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (fmt == 'u')
		*ret += ft_putunnbr_fd(va_arg(ap, unsigned int), 1);
	else if (fmt == 'x' || fmt == 'X' || fmt == 'p')
		ft_sort_arg_hexa(va_arg(ap, unsigned long), fmt, &ret);
	else if (fmt == '%')
		*ret += ft_putchar_fd('%', 1);
	else
		*i = *i - 1;
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		ret;
	int		i;

	i = 0;
	va_start(ap, fmt);
	ret = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1] != '\0')
		{
			check_arg(ap, fmt[++i], &ret, &i);
			i++;
		}
		else if (fmt[i] != '\0')
		{
			if (fmt[i] != '%')
				ret += ft_putchar_fd(fmt[i], 1);
			i++;
		}
	}
	va_end (ap);
	return (ret);
}
