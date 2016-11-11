/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:56:49 by ghery             #+#    #+#             */
/*   Updated: 2016/11/10 19:41:13 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	init(t_param *p)
{
	p->width = 1280;
	p->hight = 720;
	p->player.pos.x = 2;
	p->player.pos.y = 3;
	p->player.fov = 60;
	p->map.sizegrid = 64;
	p->player.dir.x = -1;
	p->player.dir.y = 0;
	p->player.plane.x = 0;
	p->player.plane.y = 0.66;
}	

int			main(int ac, char **av)
{
	t_param	p;
	int		fd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	fd = 0;
	if (ac == 2)
	{
		init(&p);
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return(0);
		pars(&p, fd);
		close(fd);
		while (i < p.map.sizey)
		{
			j = 0;
			while (j < p.map.sizex)
			{
				ft_printf("%d ", p.map.map[i][j]);
				j++;
			}
			i++;
			ft_printf("\n");
		}
		printf("%f\n", p.ray.pos.x);
		wolf(p);
	}
	return (0);
}
