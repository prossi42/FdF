/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 22:50:15 by prossi            #+#    #+#             */
/*   Updated: 2017/08/02 22:51:04 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		key_hook(int keycode, t_first *first)
{
	int		letter;

	letter = ft_key_number(keycode);
	if (letter == 97)
		first->prof++;
	if (letter == 98)
		first->prof--;
	return (0);
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
			if (first->pars.tabi[y][x] == 0)
			{
				first->pars.tabposx[y][x] = first->draw.posx;
				first->pars.tabposy[y][x] = first->draw.posy;
			}
			if (first->pars.tabi[y][x] != 0)
			{
				first->pars.tabposx[y][x] = first->draw.posx;
				first->pars.tabposy[y][x] = ((first->draw.posy + first->pars.tabi[y][x]) * first->prof);
			}
			first->draw.posx += first->draw.padx;
			first->draw.posy -= 1;
    		x++;
		}
		x = 0;
		first->draw.posx = (first->draw.winsize_x / 4);
		y++;
		first->draw.posy += first->draw.pady;
	}
}

int		ft_mlx(t_first *first)
{
	first->draw.init = mlx_init();
	first->draw.wdow = mlx_new_window(first->draw.init, first->draw.winsize_x, first->draw.winsize_y, "WTF !?!");
	mlx_key_hook(first->draw.wdow, key_hook, first);
	ft_tabpos(first);
	ft_map2d(first);
	// ft_map3d(first);
	mlx_loop(first->draw.init);
	return (0);
}
