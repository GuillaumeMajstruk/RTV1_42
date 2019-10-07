/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmlynarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 15:50:17 by jmlynarc          #+#    #+#             */
/*   Updated: 2019/01/27 15:50:21 by jmlynarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector			shape_normal(t_object ray, t_object object)
{
	if (object.typpe == SPHERE)
		return (sphere_normal(ray, object));
	else if (object.typpe == PLANE)
		return (plane_normal(ray, object));
	else if (object.typpe == CYLINDER)
		return (cylinder_normal(ray, object));
	else
		return (cone_normal(ray, object));
}
