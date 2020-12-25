/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 04:08:14 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/25 20:04:30 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
