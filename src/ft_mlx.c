/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 00:05:07 by prossi            #+#    #+#             */
/*   Updated: 2017/06/20 00:05:57 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void ft_trace_seg(t_param *param, t_mlx *mlx)
{
  	int 	dx;
  	int		dy;
  	int		cumul;
  	int		x;
  	int		y;

  	x = mlx->posx;
  	y = mlx->posy;
  	dx = (1.20 * mlx->posx) - mlx->posx;
  	dy = (1.20 * mlx->posy) - mlx->posy;
  	mlx_pixel_put(mlx->init, mlx->wdow, x, y, 0xFFFFFF);
  	cumul = dx / 2;
	x = mlx->posx++;
  	while (x <= (1.20 * mlx->posx))
	{
    	cumul += dy;
    	if (cumul >= dx)
		{
      		cumul -= dx;
      		y += 1;
		}
		mlx_pixel_put(mlx->init, mlx->wdow, x, y, 0xFFFFFF);
		x++;
	}
}
int			key_hook(int keycode, t_param *param)
{
	int		letter;

	letter = ft_key_number(keycode);
	// if (letter == -1)
	// 	ft_putendl("Only low Alphab. char.");
	return (0);
}

int			ft_mlx(t_param *param, t_mlx *mlx)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	if (ft_init_struct2(mlx, param) != 0)
		return (-1);
    mlx->init = mlx_init();
    mlx->wdow = mlx_new_window (mlx->init, mlx->win_size_x, mlx->win_size_y, "1st Window");
    mlx_key_hook(mlx->wdow, key_hook, &param);
	while (y < param->y_max)
	{

		while (x < param->x_max)
		{
			if (param->x_y[y][x] > 0)
			{
				ft_trace_seg(param, mlx);
				mlx->posx = mlx->posx + mlx->padding_x;
			}
			x++;
		}
		x = 0;
		mlx->posx = (mlx->win_size_x / 15);
		mlx->posy = mlx->posy + mlx->padding_y;
		y++;
	}
	mlx_loop(mlx->init);
    return (0);
}
