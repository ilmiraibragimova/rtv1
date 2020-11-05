

#include "libft.h"

int	ft_isprint(int c)
{
	int c1;

	c1 = c;
	if (c1 >= 32 && c1 <= 126)
		return (1);
	else
		return (0);
}
