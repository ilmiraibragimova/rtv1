

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	num;
	int					k;

	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	k = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			k = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (unsigned long long)(num * 10 + (*str - '0'));
		if (num > 9223372036854775807 && k == 1)
			return (-1);
		if (num > 9223372036854775807 && k == -1)
			return (0);
		str++;
	}
	return ((int)(num) * k);
}
