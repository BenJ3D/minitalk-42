#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf.h"
# include "libft.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <signal.h>

char	*ft_atob(char c);
void	sig_handler1();
void	sig_handler2();
void	ft_sendbin(char *str, int pid, int i);

#endif