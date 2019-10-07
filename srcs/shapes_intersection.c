/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:50:29 by jmlynarc          #+#    #+#             */
/*   Updated: 2019/01/27 15:50:31 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_object			intersect_object(t_object ray, t_object object)
{
	t_vector	distance;

	if (object.typpe == SPHERE)
		ray = sphere_intersection(ray, object);
	else if (object.typpe == PLANE)
		ray = plane_intersection(ray, object);
	else if (object.typpe == CYLINDER)
		ray = cylinder_intersection(ray, object);
	else if (object.typpe == CONE)
		ray = cone_intersection(ray, object, distance);
	if (ray.intersect)
	{
		ray.intersectiion.x = ray.origin.x + ray.direction.x * ray.norm;
		ray.intersectiion.y = ray.origin.y + ray.direction.y * ray.norm;
		ray.intersectiion.z = ray.origin.z + ray.direction.z * ray.norm;
	}
	return (ray);
}
