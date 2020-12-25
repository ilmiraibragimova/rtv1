/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:13:36 by ilmira            #+#    #+#             */
/*   Updated: 2020/11/25 19:29:30 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ft_ray_plane(t_raydata ray, t_obj obj)
{
	double		t;
	double		v_r;
	double		o_r;
	t_vec		x;

	x = vec_sub(obj.center, ray.point);
	o_r = vec_dot(x, obj.rot);
	v_r = vec_dot(ray.direction, obj.rot);
	t = (-o_r) / v_r;
	if ((t > 0.0001 && t < ray.t_max))
		return (t);
	return (INFINITY);
}
