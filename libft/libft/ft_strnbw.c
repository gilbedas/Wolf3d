/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 13:56:29 by ghery             #+#    #+#             */
/*   Updated: 2016/05/31 13:56:31 by ghery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strnbw(const char *s, char c)
{
	size_t	i;
	size_t	nb;

	nb = 0;
	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			if (s[i] != c && s[i - 1] == c)
				nb++;
			i++;
		}
		return (nb + 1);
	}
	return (0);
}