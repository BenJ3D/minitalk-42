/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:19:44 by bducrocq          #+#    #+#             */
/*   Updated: 2022/02/23 20:09:17 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *fmt, ...);
// FT_PRINTF_HEXA
void	ft_sort_arg_hexa(unsigned long long int nb, char arg, int **ret);
void	ft_print_hexa(unsigned long long int nb, char arg, int ***ret);
void	ft_print_pointer(unsigned long long int nb, int ***ret);

#endif