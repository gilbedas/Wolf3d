/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:58:00 by ghery             #+#    #+#             */
/*   Updated: 2016/11/10 19:41:19 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct			s_image_mlx
{
	int					width;
	int					height;
	char				*buff;
	float				tab[8];
	struct s_image_mlx	*next;
}						t_image_mlx;

typedef	struct			s_map
{
	int					**map;
	int					sizex;
	int					sizey;
	int					sizegrid;
}						t_map;

typedef	struct			s_cood
{
	double				x;
	double				y;
}						t_cood;

typedef struct			s_cooi
{
	int					x;
	int					y;
}						t_cooi;

typedef struct			s_player
{
	t_cood				pos;
	int					fov;
	t_cood				dir;
	t_cood				plane;
	t_cood				camera;
}						t_player;

typedef struct			s_draw
{
	int					linehight;
	int					start;
	int					end;
	t_cooi				pixel;
}						t_draw;

typedef struct			s_ray
{
	t_cooi				map;
	t_cood				pos;
	t_cood				dir;
	t_cood				sideDist;
	t_cood				deltaDist;
	int					hit;
	int					side;
	t_cooi				step;
	double				wallDist;
}						t_ray;

typedef struct			s_param
{
	void				*mlx;
	void				*win;
	int					width;
	int					hight;
	t_map				map;
	t_image_mlx			*img;
	t_player			player;
	t_ray				ray;
	t_draw				draw;
}						t_param;

int						pars(t_param *p, int fd);
void					wolf(t_param p);
void					ray_cast(t_param *p);
int						key_bend(int keycode, t_param *p);
void					draw(t_param *p);
#endif
