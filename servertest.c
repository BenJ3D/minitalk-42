/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   servertest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:46:48 by bducrocq          #+#    #+#             */
/*   Updated: 2022/03/12 17:53:17 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"
// #include "includes/libft.h"

static t_utils	tu;

void	receive_first_parameters(void)
{	
	tu.c = ft_btoi(tu.str);
	tu.tmpsize[tu.y] = tu.c;
	//ft_putchar_fd(tu.c, 1);
	tu.bin = BINARY_WAIT;
	tu.i = 0;
	if(tu.y == 9 && tu.bool == FALSE)
	{
		tu.size = ft_atoi(tu.tmpsize);
		 ft_putchar_fd('\n', 1);
		 ft_putnbr_fd(tu.size, 1); // affiche la taille du message a recevoir
		 ft_putchar_fd('\n', 1);
		tu.bool = TRUE;
		tu.y = 0;
		return;
	}
	if(tu.y == 9 && tu.bool == TRUE)
	{
		tu.pid = ft_atoi(tu.tmpsize);
		ft_putnbr_fd(tu.pid, 1); // affiche le pid client
		ft_putchar_fd('\n', 1);
		tu.progress =  GO_RECEIVE_MSG;
		tu.y = 0;
		return;
	}
		tu.y++;
}

void sig_handler_old(int signal, void *ptr)
{
	t_utils	*ptr2;

	ptr2 = ptr;

	ptr2->ibool = 854;
	if (signal == SIGUSR1)
	{
		//ft_putstr_fd("\n0\n", 1);
	}
	if (signal == SIGUSR2)
	{
		//ft_putstr_fd("\n1\n", 1);
	}
	ptr2->ibool++;
	tu.i += 1;
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(ptr2->ibool, 1);
	if (tu.i == 8)
	{
	ft_putstr_fd("\n8!\n", 1);
	tu.i = 0;
		//tu.progress = FINISH;
	}
}
//

int	main()
{

	static t_utils	ts;
	t_utils	*ptr;
	
	tu.ibool = 4242;
	ptr = &ts;
	ptr->i = 13;
	printf("ptr.i = %d\n", ptr->i);
	int	i;
	tu.i = 0;
	tu.y = 0;
	printf("server PID: %d\n", getpid());
	//ft_bzero(tu.str, size - 1);
	signal(SIGUSR1, (void (*)(int))sig_handler_old);
	signal(SIGUSR2, (void (*)(int))sig_handler_old);
	sig_handler_old(SIGUSR1, ptr);
	while(1)
	{
		pause();
	}
	return (0);
}

