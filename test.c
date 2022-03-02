#include "includes/minitalk.h"
#include "includes/libft.h"

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

int main()
{
	te.i = 42;
	te.bool = 0;
	printf("%i\n", te.i);
	while(te.i < 4000)
		ft_test();
	return(0);
}