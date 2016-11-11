/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 14:27:39 by ghery             #+#    #+#             */
/*   Updated: 2016/11/10 19:41:17 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static char		*puttoz(char *nb)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		nb[i] = '\0';
		i++;
	}
	return (nb);
}


static void		fill_map(t_param *p, int i, char *str)
{
	int		j;
	int		k;
	int		l;
	char	*nb;

	j = 0;
	k = 0;
	l = 0;
	nb = (char *)ft_memalloc(sizeof(char) * 10);
	p->map.map = (int **)malloc(sizeof(int *) * p->map.sizey);
	i++;
	p->map.map[l] =(int *)ft_memalloc(sizeof(int) * p->map.sizex);
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			nb[j] = str[i];
			j++;
		}
		else if (str[i] == ' ' || str[i] == '\n' || str[i] == '\0')
		{
			p->map.map[l][k] = ft_atoi(nb);
			nb = puttoz(nb);
			j = 0;
			k++;
			if (str[i] == '\n' || str[i] == '\0')
			{
				if (k != p->map.sizex || l > p->map.sizey)
					exit(0);
				k = 0;
				l++;
				if (str[i] != '\0' && l < p->map.sizey)
					p->map.map[l] =(int *)ft_memalloc(sizeof(int) * p->map.sizex);
			}
		}
		else
			exit(0);
		i++;
	}
}

static void		fill(t_param *p, char *str)
{
	int		i;
	int		j;
	char	*nb;

	i = 0;
	j = 0;
	nb = (char *)ft_memalloc(sizeof(char) * 10);
	while (str[i] != ' ' && str[i] >= 48 && str[i] <= 57)
	{
		nb[i] = str[i];
		i++;
	}
	p->map.sizex = ft_atoi(nb);
	i++;
	nb = puttoz(nb);
	while (str[i] != '\n' && str[i] >= 48 && str[i] <= 57)
	{
		nb[j] = str[i];
		i++;
		j++;
	}
	p->map.sizey = ft_atoi(nb);
	fill_map(p, i, str);
}

int				pars(t_param *p, int fd)
{
	char	*buffer;
	char	*str;
	int		ret;
	int		i;

	i = 0;
	str = (char *)ft_memalloc(1);
	buffer = (char *)ft_memalloc(1);
	while ((ret = read(fd, buffer, 1)) > 0)
	{
		str = ft_strjoin(str, buffer);
		if ((str[i] > 47 && str[i] < 58) ||\
				str[i] == ' ' || str[i] == '\n' || str[i] == '\0')
			i++;
		else
			exit(0);
	}
	str = ft_strjoin(str, "\0");
	if (ret == -1)
		return (-1);
	fill(p, str);
	free(str);
	return (0);
}
