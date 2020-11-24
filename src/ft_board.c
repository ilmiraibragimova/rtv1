/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmira <ilmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:16:52 by ilmira            #+#    #+#             */
/*   Updated: 2020/11/20 13:36:35 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	bord(t_rt *r, t_light *tmp)
{
	t_board board;

	board.x1 = r->obj[r->clos].center.x - r->obj[r->clos].radius;
	board.x2 = r->obj[r->clos].center.x + r->obj[r->clos].radius;
	board.y1 = r->obj[r->clos].center.y - r->obj[r->clos].radius;
	board.y2 = r->obj[r->clos].center.y + r->obj[r->clos].radius;
	board.z1 = r->obj[r->clos].center.z - r->obj[r->clos].radius;
	board.z2 = r->obj[r->clos].center.z + r->obj[r->clos].radius;
	if (ft_strequ(tmp->type, "point") && tmp->position.x >= board.x1\
		&& tmp->position.x <= board.x2 && tmp->position.y >= board.y1\
		&& tmp->position.y <= board.y2 && tmp->position.z >= board.z1\
		&& tmp->position.z <= board.z2)
		return (1);
	return (0);
}
