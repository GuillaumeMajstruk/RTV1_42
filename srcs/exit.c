/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmajstru <gmajstru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 11:46:36 by jmlynarc          #+#    #+#             */
/*   Updated: 2019/01/27 15:44:41 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		exit_error(t_env *env)
{
	ft_putendl("An error has occured");
	deinit_env(env);
	exit(0);
}

void		exit_normally(t_env *env)
{
	deinit_env(env);
	exit(0);
}

void		exit_usage(void)
{
	ft_putendl("Usage : ./rtv1 [scene descriptor file]");
	exit(0);
}

void		exit_invalid_file(void)
{
	ft_putendl("The file contains invalid characters.");
	exit(0);
}
