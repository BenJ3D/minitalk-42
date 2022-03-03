#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf.h"
# include "libft.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <signal.h>

enum	bool
{
	FALSE,
	TRUE
};

enum	state
{
	STEP_PARAMETER,
	NOT_FINISH,
	FINISH,
	BINARY_WAIT,
	BINARY_OK_FOR_CHAR
};
typedef struct s_utils
{
	int			i;
	int			y;
	int			size;
	char		tmpsize[11];
	int			bool; //doit disparaitre FIXME:
	enum bool	bool;
	char		*str;
	char		*msg;
	char		*tmp;
	char		c;
	int			pid;
	enum state	progress;
}	t_utils;



char	*ft_atob(char c);
void	sig_handler1();
void	sig_handler2();
void	ft_sendbin(char *str, int pid, int i);
char	ft_btoi(char *str);

#endif