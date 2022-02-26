/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:52:19 by bducrocq          #+#    #+#             */
/*   Updated: 2022/02/05 23:18:36 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// /*fonctions pour changer couleur des print f*/
void color_red () { printf("\033[1;31m"); }
void color_yellow () { printf("\033[1;33m"); }
void color_green (){  printf("\033[0;32m");}
void color_blue (){  printf("\033[0;34m");}
void color_black (){  printf("\033[0;30m");}
void color_purple (){  printf("\033[1;35m");}
void color_cyan (){  printf("\033[0;36m");}
void color_white (){  printf("\033[0;37m");}
void color_reset (){  printf("\033[0m");}