/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:44:52 by gmajstru          #+#    #+#             */
/*   Updated: 2019/01/27 16:06:39 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		init_cone(t_object *cone)
{
	cone->typpe = CONE;
	cone->angle = M_PI / 6;
	cone->direction = normalize_vector(vector(0, 1, 0));
	cone->center = point(0, 0, 0);
	cone->color = color(255, 255, 255, 0);
	cone->brillance = 0.0;
}

void		init_cylinder(t_object *cylinder)
{
	cylinder->typpe = CYLINDER;
	cylinder->radius = 1;
	cylinder->direction = normalize_vector(vector(0, 1, 0));
	cylinder->point = point(0, 0, 0);
	cylinder->color = color(255, 255, 255, 0);
	cylinder->brillance = 0.0;
}

t_object	set_brillance_if_needed(t_object object, char **line)
{
	if (line_len(line) == 2 && ft_strequ(line[0], "brillance"))
		object.brillance = fmax(fmin((float)ft_atoi(line[1]), 100), 0)
			/ 100.0;
	return (object);
}

t_object	set_angles_if_needed(t_object object, char **line)
{
	if (line_len(line) == 3 && ft_strequ(line[0], "angles"))
	{
		object.y_angle = degrees_to_radian(ft_atoi(line[1]));
		object.x_angle = degrees_to_radian(ft_atoi(line[2]));
	}
	return (object);
}
