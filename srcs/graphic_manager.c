/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 11:45:59 by jmlynarc          #+#    #+#             */
/*   Updated: 2019/01/27 15:44:42 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		calculate_scene(t_env *env)
{
	int			x;
	int			y;

	y = -1;
	while (++y < env->win_height)
	{
		x = -1;
		while (++x < env->win_width)
			pixel_raytracing(x, y, env);
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}
