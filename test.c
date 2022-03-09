#include "includes/minitalk.h"
//#include "includes/libft.h"

static t_utils	te;

void	ft_test()
{
	if(te.bool == 0)
	{
		te.i = 1;
		te.bool = 1;
	}
	else
		te.i += te.i;
	printf("%i\n", te.i);

}

int	ft_check_error_char(char c)
{
	if (c < 0 || c > 127)
		return TRUE;
	else
		return FALSE;
}

int main(int ac, char **av)
{
	// te.i = 42;
	// te.bool = 0;
	// printf("%i\n", te.i);
	// while(te.i < 4000)
	// 	ft_test();
	int		nb;
	char	str[]="0000045864";
	printf("%s\n", str);
	nb = ft_atoi(str);
	printf("%i\n", nb);

	// printf("true ?: %d\n", ft_check_error_char(ft_atoi(av[1])));
	// printf("false ?: %d\n", ft_check_error_char(ft_atoi(av[2])));
	printf("true ?: %d\n", ft_check_error_char((char)264));
	printf("false ?: %d\n", ft_check_error_char(114));
	return(0);
}
