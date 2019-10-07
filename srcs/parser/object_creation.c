/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 16:09:07 by jmlynarc          #+#    #+#             */
/*   Updated: 2019/01/27 16:09:19 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** sphere
** required structure
**
** sphere {
** radius [radius]
** center [x] [y] [z]
** color [r] [g] [b]
** }
*/

static t_object		add_new_sphere(int fd)
{
	char		**line;
	t_object	sphere;

	sphere = (t_object){.typpe = SPHERE, .radius = 1, .center = point(0, 0, 0),
		.color = color(255, 255, 255, 0), .brillance = 0.0};
	while ((line = split_new_line(fd)) && ft_strequ(line[0], "}") == FALSE)
	{
		if (line_len(line) == 2 && ft_strequ(line[0], "radius"))
			sphere.radius = ft_atoi(line[1]);
		else if (line_len(line) == 4 && ft_strequ(line[0], "center"))
			sphere.center = point(ft_atoi(line[1]), ft_atoi(line[2]),
					ft_atoi(line[3]));
		else if (line_len(line) == 4 && ft_strequ(line[0], "color"))
			sphere.color = color(ft_atoi(line[1]), ft_atoi(line[2]),
					ft_atoi(line[3]), 0);
		sphere = set_brillance_if_needed(sphere, line);
		clear_line(line);
	}
	clear_line(line);
	return (sphere);
}

/*
** plane
** required structure
**
** plane {
** normal [x] [y] [z]
** point [x] [y] [z]
** color [r] [g] [b]
** }
*/

static t_object		add_new_plane(int fd)
{
	char		**line;
	t_object	plane;

	plane = (t_object){.typpe = PLANE, .normal = vector(0, 1, 0),
		.color = color(255, 255, 255, 0), .point = point(0, 0, 0),
		.brillance = 0.0};
	while ((line = split_new_line(fd)) && ft_strequ(line[0], "}") == FALSE)
	{
		if (line_len(line) == 4 && ft_strequ(line[0], "normal"))
			plane.normal = normalize_vector(vector(ft_atoi(line[1]),
						ft_atoi(line[2]), ft_atoi(line[3])));
		else if (line_len(line) == 4 && ft_strequ(line[0], "point"))
			plane.point = point(ft_atoi(line[1]), ft_atoi(line[2]),
					ft_atoi(line[3]));
		else if (line_len(line) == 4 && ft_strequ(line[0], "color"))
			plane.color = color(ft_atoi(line[1]), ft_atoi(line[2]),
					ft_atoi(line[3]), 0);
		plane = set_brillance_if_needed(plane, line);
		clear_line(line);
	}
	clear_line(line);
	return (plane);
}

/*
** cone
** required structure
**
** cone {
** pi_divider [PI / x -> x value expected]
** direction [x] [y] [z]
** center [x] [y] [z]
** color [r] [g] [b]
** }
*/

static t_object		add_new_cone(int fd, char **line)
{
	t_object	cone;

	init_cone(&cone);
	while ((line = split_new_line(fd)) && ft_strequ(line[0], "}") == FALSE)
	{
		if (line_len(line) == 2 && ft_strequ(line[0], "pi_divider"))
			cone.angle = M_PI / ft_atoi(line[1]);
		else if (line_len(line) == 4 && ft_strequ(line[0], "direction"))
			cone.direction = normalize_vector(vector(ft_atoi(line[1]),
						ft_atoi(line[2]), ft_atoi(line[3])));
		else if (line_len(line) == 4 && ft_strequ(line[0], "center"))
			cone.center = point(ft_atoi(line[1]), ft_atoi(line[2]),
					ft_atoi(line[3]));
		else if (line_len(line) == 4 && ft_strequ(line[0], "color"))
			cone.color = color(ft_atoi(line[1]), ft_atoi(line[2]),
					ft_atoi(line[3]), 0);
		cone = set_angles_if_needed(cone, line);
		cone = set_brillance_if_needed(cone, line);
		clear_line(line);
	}
	clear_line(line);
	return (cone);
}

/*
** cylinder
** required structure
**
** cylinder {
** radius [radius]
** position [x] [y] [z]
** direction [x] [y] [z]
** color [r] [g] [b]
** angles [y_angle / longitude °] [x_angle / latitude °]
** }
*/

static t_object		add_new_cylinder(int fd, char **line)
{
	t_object	cylinder;

	init_cylinder(&cylinder);
	while ((line = split_new_line(fd)) && ft_strequ(line[0], "}") == FALSE)
	{
		if (line_len(line) == 2 && ft_strequ(line[0], "radius"))
			cylinder.radius = ft_atoi(line[1]);
		else if (line_len(line) == 4 && ft_strequ(line[0], "position"))
			cylinder.point = point(ft_atoi(line[1]), ft_atoi(line[2]),
					ft_atoi(line[3]));
		else if (line_len(line) == 4 && ft_strequ(line[0], "direction"))
			cylinder.direction = normalize_vector(vector(ft_atoi(line[1]),
						ft_atoi(line[2]), ft_atoi(line[3])));
		else if (line_len(line) == 4 && ft_strequ(line[0], "color"))
			cylinder.color = color(ft_atoi(line[1]), ft_atoi(line[2]),
					ft_atoi(line[3]), 0);
		cylinder = set_angles_if_needed(cylinder, line);
		cylinder = set_brillance_if_needed(cylinder, line);
		clear_line(line);
	}
	clear_line(line);
	return (cylinder);
}

t_object			add_new_object(int fd, char *type)
{
	char		**line;

	if (ft_strequ(type, "cylinder"))
		return (add_new_cylinder(fd, line));
	else if (ft_strequ(type, "sphere"))
		return (add_new_sphere(fd));
	else if (ft_strequ(type, "plane"))
		return (add_new_plane(fd));
	else
		return (add_new_cone(fd, line));
}
