/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_con.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:11:55 by ilmira            #+#    #+#             */
/*   Updated: 2020/11/25 19:20:58 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ft_ray_con(t_raydata ray, t_obj *obj)
{
	double	dot_ov_r;
	double	k;
	double	a;
	double	b;
	double	c;

	ray.st_cent = vec_sub(obj->center, ray.point);
	dot_ov_r = vec_dot(ray.direction, obj->rot);
	k = tan(0.5 * (obj->radius * M_PI / 180));
	k = k * k + 1.0;
	a = vec_dot(ray.direction, ray.direction) - k * pow(dot_ov_r, 2.0);
	b = 2.0 * (vec_dot(ray.direction, ray.st_cent)\
		- k * vec_dot(ray.st_cent, obj->rot) * dot_ov_r);
	c = vec_dot(ray.st_cent, ray.st_cent) - \
		k * pow(vec_dot(ray.st_cent, obj->rot), 2.0);
	return (ft_get_t(a, b, c));
}
