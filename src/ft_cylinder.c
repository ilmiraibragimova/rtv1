/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:12:39 by ilmira            #+#    #+#             */
/*   Updated: 2020/11/25 19:29:43 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ft_ray_cylinder(t_raydata ray, t_obj *obj)
{
	double	a;
	double	b;
	double	c;
	t_vec	x;

	x = vec_sub(obj->center, ray.point);
	a = vec_dot(ray.direction, ray.direction) - \
		pow(vec_dot(ray.direction, obj->rot), 2);
	b = 2 * (vec_dot(ray.direction, x) - \
		(vec_dot(ray.direction, obj->rot) * vec_dot(x, obj->rot)));
	c = vec_dot(x, x) - pow(vec_dot(x, obj->rot), 2) - pow(obj->radius, 2);
	return (ft_get_t(a, b, c));
}
