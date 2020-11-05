

int	ft_isalpha(int c)
{
	int c1;

	c1 = c;
	if ((c1 >= 'a' && c1 <= 'z') || (c1 >= 'A' && c1 <= 'Z'))
		return (1);
	else
		return (0);
}
