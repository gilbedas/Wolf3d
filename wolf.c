/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 13:45:03 by ghery             #+#    #+#             */
/*   Updated: 2016/11/10 15:31:07 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	wolf(t_param  p)
{
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, p.width, p.hight, "Wolf3D");
	ray_cast(&p);
	mlx_key_hook(p.win, &key_bend, &p);
	mlx_loop(p.mlx);
}
