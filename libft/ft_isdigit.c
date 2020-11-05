

int	ft_isdigit(int c)
{
	int c1;

	c1 = c;
	if (c1 >= '0' && c1 <= '9')
		return (1);
	else
		return (0);
}
