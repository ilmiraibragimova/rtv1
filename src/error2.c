
#include "rtv1.h"

void		error_spere(void)
{
	ft_printf("Wrong input for spere\n");
	exit(1);
}

void		error_open(void)
{
	ft_printf("Bad file\n");
	exit(1);
}

void		error_read(int fd)
{
	close(fd);
	ft_printf("Error read\n");
	exit(1);
}

void		error_malloc(int fd, char *line)
{
	close(fd);
	free(line);
	ft_printf("Error allocation\n");
	exit(1);
}

void		error_lite(void)
{
	ft_printf("Wrong light type\n");
	exit(1);
}
