/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 04:49:17 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/25 19:41:16 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		check_light(char *l_type)
{
	if (ft_strequ("ambient", l_type))
		return ;
	else if (ft_strequ("point", l_type))
		return ;
	else if (ft_strequ("direction", l_type))
		return ;
	else
		error_lite();
}

void		parse_param_light(t_rt *r, char *line)
{
	if (ft_strnequ(line, "    light-type:", 15))
		r->light->type = ft_strdup(&line[16]);
	else if (ft_strnequ(line, "    intensity:", 14))
		r->light->intensity = ((double)ft_atoi(&line[15])) / 100;
	else if (ft_strnequ(line, "    point-x:", 12))
		r->light->position.x = ft_atoi(&line[13]);
	else if (ft_strnequ(line, "    point-y:", 12))
		r->light->position.y = ft_atoi(&line[13]);
	else if (ft_strnequ(line, "    point-z:", 12))
		r->light->position.z = ft_atoi(&line[13]);
	else if (ft_strnequ(line, "    direction-x:", 16))
		r->light->direction.x = ft_atoi(&line[17]);
	else if (ft_strnequ(line, "    direction-y:", 16))
		r->light->direction.y = ft_atoi(&line[17]);
	else if (ft_strnequ(line, "    direction-z:", 16))
		r->light->direction.z = ft_atoi(&line[17]);
	else
		error_param(line);
}

void		parse_new_light(t_rt *r, int fd)
{
	int		i;
	char	*line;

	line = NULL;
	i = -1;
	if (!(r->light = (t_light *)malloc(sizeof(t_light))))
		error_malloc(fd, line);
	while (++i < 8)
	{
		if (get_next_line(fd, &line) > 0)
			parse_param_light(r, line);
		else
			error_read(fd);
		free(line);
	}
	check_light(r->light->type);
	r->light->next = NULL;
}

void		parse_old_light(t_rt *r, int fd)
{
	int		i;
	char	*line;
	t_light	*begin;

	line = NULL;
	begin = r->light;
	i = -1;
	if (!(r->light = (t_light *)malloc(sizeof(t_light))))
		error_malloc(fd, line);
	r->light->next = begin;
	while (++i < 8)
	{
		if (get_next_line(fd, &line) > 0)
			parse_param_light(r, line);
		else
			error_read(fd);
		free(line);
	}
	check_light(r->light->type);
}

void		parse_light(t_rt *r, int fd)
{
	if (r->light == NULL)
		parse_new_light(r, fd);
	else
		parse_old_light(r, fd);
}
