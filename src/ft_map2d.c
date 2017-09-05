/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 01:47:32 by prossi            #+#    #+#             */
/*   Updated: 2017/08/05 01:47:51 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_segment_td(t_first *first)
{
	int		i;

	first->pars.cumul = first->pars.dy / 2;
	i = 1;
	while (i <= first->pars.dy)
	{
		first->pars.yi += first->pars.yinc;
		first->pars.cumul += first->pars.dx;
		if (first->pars.cumul >= first->pars.dy)
		{
			first->pars.cumul -= first->pars.dy;
			first->pars.xi += first->pars.xinc;
		}
		mlx_pixel_put_to_image(first->draw, first->pars.xi, first->pars.yi \
			, 0xFFFFFF);
		i++;
	}
}

void	ft_segment_sd(t_first *first)
{
	int		i;

	first->pars.cumul = first->pars.dx / 2;
	i = 1;
	while (i <= first->pars.dx)
	{
		first->pars.xi += first->pars.xinc;
		first->pars.cumul += first->pars.dy;
		if (first->pars.cumul >= first->pars.dx)
		{
			first->pars.cumul -= first->pars.dx;
			first->pars.yi += first->pars.yinc;
		}
		mlx_pixel_put_to_image(first->draw, first->pars.xi, first->pars.yi \
			, 0xFFFFFF);
		i++;
	}
}

void	ft_segment(t_first *first)
{
	int		i;

	first->pars.dx = first->pars.xf - first->pars.xi;
	first->pars.dy = first->pars.yf - first->pars.yi;
	first->pars.xinc = (first->pars.dx > 0) ? 1 : -1;
	first->pars.yinc = (first->pars.dy > 0) ? 1 : -1;
	first->pars.dx = abs(first->pars.dx);
	first->pars.dy = abs(first->pars.dy);
	mlx_pixel_put_to_image(first->draw, first->pars.xi, first->pars.yi, \
		0xFFFFFF);
	if (first->pars.dx > first->pars.dy)
		ft_segment_sd(first);
	else
	{
		ft_segment_td(first);
	}
}

void	ft_trace(t_first *first, int x, int y)
{
	if ((x + 1) < first->pars.x_max)
	{
		first->pars.xi = first->pars.tabposx[y][x];
		first->pars.yi = first->pars.tabposy[y][x];
		first->pars.xf = first->pars.tabposx[y][x + 1];
		first->pars.yf = first->pars.tabposy[y][x + 1];
		ft_segment(first);
	}
	if ((y + 1) < first->pars.y_max - 1)
	{
		first->pars.xi = first->pars.tabposx[y][x];
		first->pars.yi = first->pars.tabposy[y][x];
		first->pars.xf = first->pars.tabposx[y + 1][x];
		first->pars.yf = first->pars.tabposy[y + 1][x];
		ft_segment(first);
	}
}

void	ft_map2d(t_first *first)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < (first->pars.y_max - 1))
	{
		while (x < first->pars.x_max)
		{
			mlx_pixel_put_to_image(first->draw, first->pars.tabposx[y][x], \
				first->pars.tabposy[y][x], 0xFFFFFF);
			ft_trace(first, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}
