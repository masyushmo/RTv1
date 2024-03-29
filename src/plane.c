/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:14:34 by mmasyush          #+#    #+#             */
/*   Updated: 2019/10/30 14:19:56 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv.h"

t_roots		inter_plane(t_vector camera, t_vector d, int n, t_rtv *rtv)
{
	double d_dir;
	double c_norm;

	d_dir = vect_dot(d, rtv->map.obj[n].plane.norm);
	if (fabs(d_dir) < 0)
		return ((t_roots){T_MAX + 1, T_MAX + 1});
	else
	{
		c_norm = vect_dot(camera - rtv->map.obj[n].plane.o, \
			rtv->map.obj[n].plane.norm);
		return ((t_roots){T_MAX + 1, -c_norm / d_dir});
	}
}

t_vector	plane_norm(t_rtv *rtv, t_calc *calc)
{
	calc->point = calc->camera + vect_mult(calc->dir, calc->check.min_dist);
	if (vect_dot(calc->dir, \
		rtv->map.obj[calc->check.close_obj].plane.norm) < 0)
		calc->normal = rtv->map.obj[calc->check.close_obj].plane.norm;
	else
		calc->normal = -rtv->map.obj[calc->check.close_obj].plane.norm;
	calc->dir = -calc->dir;
	return (vect_mult(rtv->map.obj[calc->check.close_obj].plane.col,
		calc_light(rtv, calc, rtv->map.obj[calc->check.close_obj].plane.spec)));
}

int			save_plane(t_map *map, char *line)
{
	char		*l;

	l = ft_strtrim(line);
	if (ft_strncmp("specular = ", l, ft_strlen("specular = ")) == 0)
		map->obj[map->onum].plane.spec = get_int(l, \
			(int)ft_strlen("specular = "), (int)ft_strlen(l));
	else if (ft_strncmp("normal = ", l, ft_strlen("normal = ")) == 0)
		map->obj[map->onum].plane.norm = get_vect(l);
	else if (ft_strncmp("position = ", l, ft_strlen("position = ")) == 0)
		map->obj[map->onum].plane.o = get_vect(l);
	else if (ft_strncmp("color = ", l, ft_strlen("color = ")) == 0)
		map->obj[map->onum].plane.col = get_vect(l);
	else
		ft_error(BADLINE);
	free(l);
	return (1);
}
