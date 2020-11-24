/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilmira <ilmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:15:58 by ilmira            #+#    #+#             */
/*   Updated: 2020/11/06 20:15:58 by ilmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "veclib.h"

t_vec	vec_norm(t_vec v1)
{
	double inv;

	inv = 1 / vec_len(v1);
	return (vec_scale(v1, inv));
}