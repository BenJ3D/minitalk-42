/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:05:16 by bducrocq          #+#    #+#             */
/*   Updated: 2022/02/22 19:01:53 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	pid = atoi(argv[1]);
	kill(pid, SIGSTOP);
	return (0);
}