/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 16:33:47 by bducrocq          #+#    #+#             */
/*   Updated: 2022/03/13 17:19:32 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <signal.h>
#ifndef SPEED
# define SPEED 100
#endif

enum	e_bool
{
	FALSE,
	TRUE
};

enum	e_state
{
	WAIT_PARAMETER,
	GO_RECEIVE_MSG
};

enum	e_bin
{
	BINARY_WAIT,
	BINARY_OK_FOR_CHAR
};
typedef struct s_serv
{
	int				i;
	char			*str;
	enum e_bin		bin;
}	t_serv;

typedef struct s_tools
{
	int				i;
	int				y;
	int				size;
	char			tmpsize[11];
	enum e_bool		bool;
	char			*str;
	char			*msg;
	char			*tmp;
	char			c;
	int				pid;
	enum e_bin		bin;
	enum e_state	progress;
}	t_tools;

char	*ft_atob(char c);
void	ft_sendbin(char *str, int pid, int speed);
int		ft_btoi(char *str);
void	displays_message_info(t_tools *pto);

#endif