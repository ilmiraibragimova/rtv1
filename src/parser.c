#include "rtv1.h"

void parse1(char **box, t_rt *r)
{
	printf("%ld\n", sizeof(box[3]));
		if (ft_strequ(box[0], "cam:"))
			ft_cam(box,r);
		else if (ft_strequ(box[0], "sphere:"))
			ft_sphere(box, r);
		else if (ft_strequ(box[0], "plane:"))
			ft_plane(r, box);
		else if (ft_strequ(box[0], "cylinder:"))
			ft_cylinder(r, box);
		else if (ft_strequ(box[0], "cone:"))
			ft_con(r, box);
		else if (ft_strequ(box[0], "light:"))
			ft_light(box, r);
}

void ft_parser(char *arg, t_rt *r)
{
	int fd;
	char *line;
	char **box;

	ft_count_obj(r, arg);
	if (!(r->obj = ft_memalloc(sizeof(t_obj) * r->amount_obj)))
		return;
	//printf("%ld\n", sizeof(t_light));
	if ((fd = open(arg, O_RDONLY)) < 0)
		ft_put_error("Can't open the file");
	while (get_next_line(fd, &line))
	{
		box = ft_strsplit(line, ' ');
		parse1(box, r);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
}

