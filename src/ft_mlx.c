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

void	ft_trace_map(t_main *main, int option)
{
	int		i;

	i = 0;
	if (option == 1 || option == 2)
	{
		while (i < main->draw.padx)
		{
			mlx_pixel_put(main->draw.init, main->draw.wdow, main->draw.posx, main->draw.posy, 0xFFFFFF);
			main->draw.posx++;
			i++;
		}
		main->draw.posx = main->draw.posx - main->draw.padx;
	}
	if (option == 1)
	{
		i = 0;
		while (i < main->draw.pady)
		{
			mlx_pixel_put(main->draw.init, main->draw.wdow, main->draw.posx, main->draw.posy, 0xFFFFFF);
			main->draw.posy++;
			i++;
		}
		main->draw.posy = main->draw.posy - main->draw.pady;
	}
}

void	ft_trace_seg(t_main *main)
{
	int 	dx;
	int		dy;
	int		cumul;
	int		x;
	int		y;

	x = main->draw.posx;
	y = main->draw.posy;
	dx = (1.20 * main->draw.posx) - main->draw.posx;
	dy = (1.20 * main->draw.posy) - main->draw.posy;
	main->draw.dx = dx;
	main->draw.dy = dy;
	mlx_pixel_put(main->draw.init, main->draw.wdow, x, y, 0xFFFFFF);
	cumul = dx / 2;
	x = main->draw.posx++;
	while (x <= (1.20 * main->draw.posx))
	{
		cumul += dy;
		if (cumul >= dx)
		{
			cumul -= dx;
			y += 1;
		}
		mlx_pixel_put(main->draw.init, main->draw.wdow, x, y, 0xFFFFFF);
		x++;
	}
}
void	ft_map2d(t_main *main)
{
	int		y;
	int		x;
	int		i;

	y = 0;
	x = 0;
	i = 0;
	while (y < main->pars.y_max - 1)
	{
		while (x < main->pars.x_max)
		{
			if (main->pars.tabi[y][x] == 0)
			{
				if (i != 0)
				{
					main->draw.posx = main->draw.posx - main->draw.padx;
					i = 0;
				}
				mlx_pixel_put(main->draw.init, main->draw.wdow, main->draw.posx, main->draw.posy, 0xFFFFFF);
				if (y != (main->pars.y_max - 2))
					ft_trace_map(main, 1);
				else
					ft_trace_map(main, 2);

			}
			else
			{
				i = 0;
				ft_trace_seg(main);
				if (main->pars.tabi[y][x - 1] == 0)
				{
					while (i < (main->draw.padx * 1.20))
					{
						mlx_pixel_put(main->draw.init, main->draw.wdow, main->draw.dx + main->draw.posx, main->draw.dy + 1 + main->draw.posy, 0xFFFFFF);
						main->draw.dx++;
						i++;
					}
				}
				i = 0;
				if (y != main->pars.y_max - 2)
				{
					while (i < (main->draw.pady * 1.20))
					{
						mlx_pixel_put(main->draw.init, main->draw.wdow, main->draw.posx * 1.20, main->draw.dy + 1 + main->draw.posy, 0xFFFFFF);
						main->draw.dy++;
						i++;
					}
					main->draw.dx = main->draw.posx - main->draw.padx;
					i = 0;
					i++;
				}
			}
			main->draw.posx = main->draw.posx + main->draw.padx;
			x++;
		}
		x = 0;
		main->draw.posx = (main->draw.winsize_x) / 10;
		main->draw.posy = main->draw.posy + main->draw.pady;
		y++;
	}
}

int		key_hook(int keycode, t_main *main)
{
	int		letter;

	letter = ft_key_number(keycode);
	return (0);
}

int		ft_mlx(t_main *main)
{
	main->draw.init = mlx_init();
	main->draw.wdow = mlx_new_window(main->draw.init, main->draw.winsize_x, main->draw.winsize_y, "WTF !?!");
	mlx_key_hook(main->draw.wdow, key_hook, main);
	ft_map2d(main);
	mlx_loop(main->draw.init);
	return (0);
}
