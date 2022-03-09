/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:44:26 by bducrocq          #+#    #+#             */
/*   Updated: 2022/03/09 19:17:05 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

/**
 * @brief Traite les signals USR1 et 2
 * 
 * @param signal 
 * @param tu adress struct utils principal
 */
void sig_handler(int signal, t_utils *tu)
{
	if (signal == SIGUSR1)
		tu->str[tu->i] = '0';
	if (signal == SIGUSR2)
		tu->str[tu->i] = '1';
	tu->i += 1;
	if (tu->i == 8)
	{
		tu->str[tu->i] = '\0';
		tu->bin = BINARY_OK_FOR_CHAR;
		//g_tu.progress = FINISH;
	}
}

/**
 * @brief pass a char to binary char (ex : "42" -> "00004242")
 * 
 * @param c 
 * @return char* -> pensser a la free()
 */
char	*ft_atob(char c)
{
	int	i;
	int	base;
	char *str;

	str = malloc(sizeof(char) * 9);
	if(!str)
		return (NULL);
	base = 128;
	i = 0;
	while (base >= 1)
	{
		if((c / base) == 1)
		{
			str[i] = '1';
			c = c - base;
		}
		else 
			str[i] = '0';
		i++;	
		if (base == 1)
			break;
		base = base / 2;
	}
	str[i] = '\0';
	return(str);
}

int	ft_btoi(char *str)
{
	int		i;
	int		base;
	char	ichar;

	i = 0;
	base = 128;
	while (i < 8)
	{
		if (str[i] == '1')
			ichar += base;
		base = base / 2;
		i++;
	}
	return (ichar);
}

// void	ft_strjoin_minitalk(char **dst, char *line2, char *buf2, size_t buf_end)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	srcslen;
// 	size_t	start;

// 	start = ft_find_start(buf2);
// 	srcslen = ft_strlen(line2);
// 	srcslen = srcslen + ((buf_end + 1) - start);
// 	*dst = malloc((sizeof(char) * srcslen) + 1);
// 	if (!dst)
// 		return ;
// 	j = 0;
// 	i = 0;
// 	while (line2[i])
// 		dst[0][j++] = line2[i++];
// 	i = start;
// 	while (buf2[i] && i <= (size_t)buf_end)
// 		dst[0][j++] = buf2[i++];
// 	dst[0][j] = '\0';
// 	if (line2)
// 		free (line2);
// 	if (BUFFER_SIZE > 1)
// 		ft_buf_process(&*buf2);
// 	else if (BUFFER_SIZE <= 1)
// 		buf2[0] = '\0';
// }


// int main(int argc, char **argv)
// {	
// 	char *str;
// 	int		c;

// 	str = ft_atob(argv[1][0]);
// 	printf("%s\n", str);
// 	c = ft_btoi(str);
// 	printf("%c\n", c);
// 	free(str);
// 	return(0);
// }