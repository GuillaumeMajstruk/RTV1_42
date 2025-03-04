/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 14:16:53 by jmlynarc          #+#    #+#             */
/*   Updated: 2019/01/27 15:42:34 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float		vector_norm(t_vector vector)
{
	double		norm;

	norm = sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
	return (norm);
}

float		dot_product(t_vector vect_1, t_vector vect_2)
{
	double		product;

	product = (vect_1.x * vect_2.x) +
				(vect_1.y * vect_2.y) +
				(vect_1.z * vect_2.z);
	return (product);
}

t_vector	cross_product(t_vector vect_1, t_vector vect_2)
{
	t_vector	product;

	product.x = vect_1.y * vect_2.z - vect_2.y * vect_1.z;
	product.y = vect_1.z * vect_2.x - vect_2.z * vect_1.x;
	product.z = vect_1.x * vect_2.y - vect_2.x * vect_1.y;
	return (product);
}

t_vector	normalize_vector(t_vector vector)
{
	float		norm;

	norm = vector_norm(vector);
	vector.x /= norm;
	vector.y /= norm;
	vector.z /= norm;
	return (vector);
}

float		points_norm(t_point p1, t_point p2)
{
	float		distance;

	distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) +
			pow(p2.z - p1.z, 2));
	return (distance);
}
