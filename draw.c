/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:31:17 by ghery             #+#    #+#             */
/*   Updated: 2016/11/10 19:41:29 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	drawcalc(t_param *p)
{
	p->draw.linehight = (int)(p->hight / p->ray.wallDist);
//	ft_printf("%d, %d\n", p->draw.linehight, p->ray.wallDist);
	p->draw.start = -p->draw.linehight / 2 + p->hight / 2;
	if (p->draw.start < 0)
		p->draw.start = 0;
	p->draw.end = p->draw.linehight / 2 + p->hight / 2;
	if (p->draw.end >= p->hight)
		p->draw.end = p->hight - 1;
}

void		draw(t_param *p)
{
	int y;
	int	x;

	y = 0;
	x = p->draw.pixel.x;
	drawcalc(p);
	while (y < p->hight)
	{
//		printf("ca passe\n");
//		ft_printf("%d, %d, %d, %d\n", p->draw.start, p->draw.end, y, p->ray.side);
		if (y >= p->draw.start && y <= p->draw.end && p->ray.side == 1)
		{
			(p->img->buff[(4 * x) + (4 * y * p->img->width)]) = 0;
			(p->img->buff[(4 * x) + (4 * y * p->img->width) + 1]) = 255;
			(p->img->buff[(4 * x) + (4 * y * p->img->width) + 2]) = 0;
		}
		else if (y >= p->draw.start && y <= p->draw.end)
		{
			(p->img->buff[(4 * x) + (4 * y * p->img->width)]) = 0;
			(p->img->buff[(4 * x) + (4 * y * p->img->width) + 1]) = 0;
			(p->img->buff[(4 * x) + (4 * y * p->img->width) + 2]) = 255;
		}
		y++;
	}
	printf("voila\n");
	p->draw.pixel.x = x + 1;
}
