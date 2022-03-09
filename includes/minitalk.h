/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:13:20 by bducrocq          #+#    #+#             */
/*   Updated: 2022/03/09 19:13:21 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf.h"
# include "../libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <signal.h>

enum	e_bool
{
	FALSE,
	TRUE
};

enum	e_state
{
	STEP_PARAMETER,
	NOT_FINISH,
	FINISH,
	START_RECEIVE_MSG
};

enum	e_bin
{
	BINARY_WAIT,
	BINARY_OK_FOR_CHAR
};
typedef struct s_utils
{
	int				i;
	int				y;
	int				x;
	int				size;
	char			tmpsize[11];
	int				ibool; //doit disparaitre FIXME:
	enum e_bool		bool;
	char			*str;
	char			*msg;
	char			*tmp;
	char			c;
	int				pid;
	enum e_bin		bin;
	enum e_state	progress;
}	t_utils;



char	*ft_atob(char c);
void	sig_handler(int signal, t_utils *tu);
void	ft_sendbin(char *str, int pid, int i);
int		ft_btoi(char *str);

#endif