
#include "rtv1.h"

void		check_cylinder(t_obj *cyl)
{
	if (cyl->color[0] < 0 || cyl->color[0] > 255
	|| cyl->color[1] < 0 || cyl->color[1] > 255
	|| cyl->color[2] < 0 || cyl->color[2] > 255
	|| cyl->radius < 0.1)
		error_cyl();
}

void		parse_param_cyl(t_rt *r, char *line)
{
	if (ft_strnequ(line, "    point-x:", 12))
		r->obj[r->count].center.x = (double)ft_atoi(&line[13]);
	else if (ft_strnequ(line, "    point-y:", 12))
		r->obj[r->count].center.y = (double)ft_atoi(&line[13]);
	else if (ft_strnequ(line, "    point-z:", 12))
		r->obj[r->count].center.z = (double)ft_atoi(&line[13]);
	else if (ft_strnequ(line, "    radius:", 11))
		r->obj[r->count].radius = (double)ft_atoi(&line[12]) / 10;
	else if (ft_strnequ(line, "    rot-x:", 10))
		r->obj[r->count].rot.x = (double)ft_atoi(&line[11]);
	else if (ft_strnequ(line, "    rot-y:", 10))
		r->obj[r->count].rot.y = (double)ft_atoi(&line[11]);
	else if (ft_strnequ(line, "    rot-z:", 10))
		r->obj[r->count].rot.z = (double)ft_atoi(&line[11]);
	else if (ft_strnequ(line, "    red:", 8))
		r->obj[r->count].color[0] = (ft_atoi(&line[9]));
	else if (ft_strnequ(line, "    green:", 10))
		r->obj[r->count].color[1] = (ft_atoi(&line[11]));
	else if (ft_strnequ(line, "    blue:", 9))
		r->obj[r->count].color[2] = (ft_atoi(&line[10]));
	else if (ft_strnequ(line, "    specular:", 13))
		r->obj[r->count].specular = (double)ft_atoi(&line[14]);
	else
		error_param(line);
}

void		parse_cylinder(t_rt *r, int fd)
{
	int		i;
	char	*line;

	i = -1;
	while (++i < 11)
	{
		if (get_next_line(fd, &line) > 0)
			parse_param_cyl(r, line);
		else
			error_read(fd);
		free(line);
	}
	r->obj[r->count].rot = vec_norm(r->obj[r->count].rot);
	check_cylinder(&r->obj[r->count]);
	r->obj[r->count].name = "cylinder";
	r->count++;
}
