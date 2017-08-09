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

void    ft_segment(int xi,int yi,int xf,int yf, t_first *first)
{
      int   dx;
      int   dy;
      int   i;
      int   xinc;
      int   yinc;
      int   cumul;
      int   x;
      int   y;

      x = xi;
      y = yi;
      dx = xf - xi;
      dy = yf - yi;
      xinc = ( dx > 0 ) ? 1 : -1;
      yinc = ( dy > 0 ) ? 1 : -1;
      dx = abs(dx);
      dy = abs(dy);
      mlx_pixel_put_to_image(first->draw, x, y, 0xFFFFFF);
      if (dx > dy)
      {
            cumul = dx / 2;
            i = 1;
            while (i <= dx)
            {
                x += xinc;
                cumul += dy;
                if (cumul >= dx)
                {
                    cumul -= dx;
                    y += yinc;
                }
                mlx_pixel_put_to_image(first->draw, x, y, 0xFFFFFF);
                i++;
            }
      }
      else
      {
          cumul = dy / 2;
          i = 1;
          while (i <= dy)
          {
              y += yinc ;
              cumul += dx ;
              if ( cumul >= dy )
              {
                  cumul -= dy ;
                  x += xinc ;
              }
              mlx_pixel_put_to_image(first->draw, x, y, 0xFFFFFF);
              i++;
          }
      }
}

void        ft_trace(t_first *first, int x, int y)
{
    if ((x + 1) < first->pars.x_max)
        ft_segment(first->pars.tabposx[y][x], first->pars.tabposy[y][x], first->pars.tabposx[y][x + 1], first->pars.tabposy[y][x + 1], first);
    if ((y + 1) < first->pars.y_max - 1)
        ft_segment(first->pars.tabposx[y][x], first->pars.tabposy[y][x], first->pars.tabposx[y + 1][x], first->pars.tabposy[y + 1][x], first);
}

void		ft_map2d(t_first *first)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < (first->pars.y_max - 1))
	{
		while (x < first->pars.x_max)
		{
    		mlx_pixel_put_to_image(first->draw, first->pars.tabposx[y][x], first->pars.tabposy[y][x], 0xFFFFFF);
            ft_trace(first, x, y);
    		x++;
		}
		x = 0;
		y++;
	}
}
