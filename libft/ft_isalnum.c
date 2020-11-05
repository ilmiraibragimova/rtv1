

#include "libft.h"

int	ft_isalnum(int c)
{
	int c1;

	c1 = c;
	if ((c1 >= '0' && c1 <= '9')\
	|| (c1 >= 'a' && c1 <= 'z') || (c1 >= 'A' && c1 <= 'Z'))
		return (1);
	else
		return (0);
}
