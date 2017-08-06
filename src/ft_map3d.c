/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/05 03:26:41 by prossi            #+#    #+#             */
/*   Updated: 2017/08/05 03:26:43 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

// void        ft_tracey(t_first *first, int y, int x)
// {
//     int     i;
//     int     j;
//
//     i = 0;
//     j = first->pars.tabposy[y][x];
//     while (i < first->draw.pady)
//     {
//         mlx_pixel_put(first->draw.init, first->draw.wdow, first->pars.tabposx[y][x], j, 0xFFFFFF);
//         i++;
//         j++;
//     }
// }
//
// void        ft_tracex(t_first *first, int y, int x)
// {
//     int     j;
//     int     i;
//
//     j = 0;
//     i = 0;
//     j = first->pars.tabposx[y][x];
//     while (i < first->draw.padx)
//     {
//         mlx_pixel_put(first->draw.init, first->draw.wdow, j, first->pars.tabposy[y][x], 0xFFFFFF);
//         i++;
//         j++;
//     }
// }
void        ft_segment2(int xi,int yi,int xf,int yf, t_first *first)
{
    int   dx;
    int   dy;
    int   cumul;
    int   x;
    int   y;

    x = xi;
    y = yi;
    dx = xf - xi;
    dy = yf - yi;
    mlx_pixel_put(first->draw.init, first->draw.wdow, x, y, 0xFFFFFF);
    cumul = dx / 2;
    x = xi++;
    while (x <= xf)
    {
        cumul += dy;
        if (cumul >= dx)
        {
            cumul -= dx;
            y += 1;
        }
        mlx_pixel_put(first->draw.init, first->draw.wdow, x, y, 0xFFFFFF);
        x++;
    }
}

void        ft_segment(int xi,int yi,int xf,int yf, t_first *first)
{
      int   dx;
      int   dy;
      int   cumul;
      int   x;
      int   y;

      x = xi;
      y = yi;
      dx = xf - xi;
      dy = yf - yi;
      mlx_pixel_put(first->draw.init, first->draw.wdow, x, y, 0xFFFFFF);
      cumul = dx / 2;
      x = xi++;
      while (x <= xf)
      {
          cumul += dy;
          if (cumul >= dx)
          {
              cumul -= dx;
              y += 1;
          }
          mlx_pixel_put(first->draw.init, first->draw.wdow, x, y, 0xFFFFFF);
          x++;
      }
}

void		ft_map3d(t_first *first)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < (first->pars.y_max - 1))
	{
		while (x < first->pars.x_max)
		{
            if (first->pars.tabposx[y][x] <= first->pars.tabposx[y][x + 1])
                ft_segment(first->pars.tabposx[y][x], first->pars.tabposy[y][x], first->pars.tabposx[y][x + 1], first->pars.tabposy[y][x + 1], first);
            // else
            //     ft_segment2(first->pars.tabposx[y][x], first->pars.tabposy[y][x], first->pars.tabposx[y][x - 1], first->pars.tabposy[y][x], first);
    		x++;
		}
		x = 0;
		y++;
	}
}
