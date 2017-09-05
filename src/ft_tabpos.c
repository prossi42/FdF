/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:03:12 by prossi            #+#    #+#             */
/*   Updated: 2017/09/05 11:03:15 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_tabpos_sd(t_first *first, int x, int y)
{
	if (first->pars.tabi[y][x] == 0)
	{
		first->pars.tabposx[y][x] = first->draw.posx;
		first->pars.tabposy[y][x] = first->draw.posy;
	}
	if (first->pars.tabi[y][x] != 0)
	{
		first->pars.tabposx[y][x] = first->draw.posx + \
		(first->pars.tabi[y][x] * first->draw.prof);
		first->pars.tabposy[y][x] = first->draw.posy + \
		(first->pars.tabi[y][x] * first->draw.prof);
	}
}

void	ft_tabpos(t_first *first)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < (first->pars.y_max - 1))
	{
		while (x < first->pars.x_max)
		{
			ft_tabpos_sd(first, x, y);
			first->draw.posx += first->draw.padx;
			first->draw.posy += first->draw.rot;
			first->draw.posx -= first->draw.rot;
			x++;
		}
		first->draw.posx += first->draw.rot * x;
		first->draw.posy -= first->draw.rot * x;
		x = 0;
		first->draw.posx = first->draw.x;
		y++;
		first->draw.posy += first->draw.pady;
	}
}
