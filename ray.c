/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:17:57 by ghery             #+#    #+#             */
/*   Updated: 2016/11/10 19:41:22 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	sideDist(t_param *p)
{
	if (p->ray.dir.x < 0)
	{
//		printf("%f\n", p->ray.deltaDist.x);
		p->ray.step.x = -1;
		p->ray.sideDist.x = (p->ray.pos.x - p->ray.map.x)\
							* p->ray.deltaDist.x;
	}
	else
	{
//		printf("ici\n");
		p->ray.step.x = 1;
		p->ray.sideDist.x = ( p->ray.map.x + 1.0 -  p->ray.pos.x)\
							* p->ray.deltaDist.x;
	}
	if (p->ray.dir.y < 0)
	{
		p->ray.step.y = -1;
		p->ray.sideDist.y = (p->ray.pos.y - p->ray.map.y)\
							* p->ray.deltaDist.y;
	}
	else
	{
		p->ray.step.y = 1;
		p->ray.sideDist.y = ( p->ray.map.y + 1.0 -  p->ray.pos.y)\
							* p->ray.deltaDist.y;
	}
}

static void	ray(t_param *p)
{
	while (p->ray.hit == 0)
	{
		if (p->ray.sideDist.x < p->ray.sideDist.y)
		{
//			printf("la ?\n");
			p->ray.sideDist.x = p->ray.sideDist.x + p->ray.deltaDist.x;
			p->ray.map.x = p->ray.map.x + p->ray.step.x;
			p->ray.side = 0;
		}
		else
		{
//			printf("t'est ou ?\n");
			p->ray.sideDist.y = p->ray.sideDist.y + p->ray.deltaDist.y;
			p->ray.map.y = p->ray.map.y + p->ray.step.y;
			p->ray.side = 1;
		}
//		printf("%d, %d\n", p->ray.map.x, p->ray.map.y);
		if (p->map.map[p->ray.map.y][p->ray.map.x] > 0)
			p->ray.hit = 1;
//		printf("%f, %f\n", p->ray.Dist.x, p->ray.sideDist.y);
	}
}

static void	proj_dist(t_param *p)
{
	if (p->ray.side == 0)
	{
//		printf("la\n");
		p->ray.wallDist = (p->ray.map.x - p->ray.pos.x +\
				(1 - p->ray.step.x) / 2) / p->ray.dir.x;
	}
	else
	{
	//	printf("%d, %f, %d, %f\n",\
	//			p->ray.map.y, p->ray.pos.y, p->ray.step.y, p->ray.dir.y);
		p->ray.wallDist = (p->ray.map.y - p->ray.pos.y +\
				(1 - p->ray.step.y) / 2) / p->ray.dir.y;
	}
}

void		ray_cast(t_param *p)
{
	int		i;

	i = 0;
	p->img = mlx_new_image(p->mlx, p->width, p->hight);
	p->draw.pixel.x = 0;
	p->draw.pixel.y = 0;
//	printf("%f\n", p->player.pos.x);
	while (i <= p->width)
	{
		p->player.camera.x = (2 * i) / ((double)(p->width)) - 1;
		p->ray.pos.x = p->player.pos.x;
		p->ray.pos.y = p->player.pos.y;
		p->ray.dir.x = p->player.dir.x + (p->player.plane.x * p->player.camera.x);
//		printf("%f, %f, %f\n", p->player.dir.y, p->player.plane.x, );
		p->ray.dir.y = p->player.dir.y + (p->player.plane.y * p->player.camera.x);
		p->ray.map.x = (int)(p->ray.pos.x);
		p->ray.map.y = (int)(p->ray.pos.x);
		p->ray.deltaDist.x = sqrt(1 + (p->ray.dir.y * p->ray.dir.y)\
				/ (p->ray.dir.x * p->ray.dir.x));
		p->ray.deltaDist.y = sqrt(1 + (p->ray.dir.x * p->ray.dir.x)\
				/ (p->ray.dir.y * p->ray.dir.y));
		p->ray.hit = 0;
		sideDist(p);
		printf("oui ^^\n");
		ray(p);
		printf("la peux etre ?\n");
		proj_dist(p);
		printf("la?\n");
		draw(p);
		i++;
	}
	mlx_clear_window(p->mlx, p->win);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_destroy_image(p->mlx, p->img);
}
