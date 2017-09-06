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

void	mlx_pixel_put_to_image(t_draw draw, int x, int y, int color)
{
	int			color1;
	int			color2;
	int			color3;
	int			bit_pix;
	float		img_size;

	img_size = WINSIZE_X * WINSIZE_Y * draw.bpp / 8;
	if (x < 0 || y < 0 || y * draw.size_line + x * draw.bpp / 8 > \
		img_size
		|| x >= draw.size_line / (draw.bpp / 8) || y >= img_size / \
		draw.size_line)
		return ;
	color1 = color;
	color2 = color >> 8;
	color3 = color >> 16;
	bit_pix = draw.bpp / 8;
	draw.map[y * draw.size_line + x * bit_pix] = color1;
	draw.map[y * draw.size_line + x * bit_pix + 1] = color2;
	draw.map[y * draw.size_line + x * bit_pix + 2] = color3;
}

int		key_hook_sd(int keycode, t_first *first)
{
	if (keycode == 36)
		ft_init_struct(first, 2);
	if (keycode == 0)
		first->draw.rot++;
	if (keycode == 11)
		first->draw.rot--;
	if (keycode == 124)
		first->draw.x += 2;
	if (keycode == 123)
		first->draw.x -= 2;
	if (keycode == 125)
		first->draw.y += 2;
	if (keycode == 126)
		first->draw.y -= 2;
	if (keycode == 69)
		first->draw.prof += 2;
	if (keycode == 78)
		first->draw.prof -= 2;
	if (keycode == 67)
		first->draw.zoom++;
	if (keycode == 75)
		first->draw.zoom--;
	return (0);
}

int		key_hook(int keycode, t_first *first)
{
	if (keycode == 53)
	{
		ft_putstr("\n	End Of Program");
		exit(-1);
	}
	key_hook_sd(keycode, first);
	mlx_destroy_image(first->draw.init, first->draw.img);
	ft_init_struct(first, 3);
	first->draw.img = mlx_new_image(first->draw.init, WINSIZE_X, WINSIZE_Y);
	first->draw.map = mlx_get_data_addr(first->draw.img, &first->draw.bpp, \
		&first->draw.size_line, &first->draw.endian);
	ft_tabpos(first);
	ft_map2d(first);
	mlx_put_image_to_window(first->draw.init, first->draw.wdow, \
		first->draw.img, 0, 0);
	return (0);
}

int		ft_mlx(t_first *first)
{
	first->draw.init = mlx_init();
	first->draw.wdow = mlx_new_window(first->draw.init, WINSIZE_X, WINSIZE_Y, \
		"WTF !?!");
	first->draw.img = mlx_new_image(first->draw.init, WINSIZE_X, WINSIZE_Y);
	if (!(first->draw.map = (char *)malloc(sizeof(char) * (WINSIZE_X * \
		WINSIZE_Y * first->draw.bpp))))
		return (-1);
	first->draw.map = mlx_get_data_addr(first->draw.img, &first->draw.bpp, \
		&first->draw.size_line, &first->draw.endian);
	ft_tabpos(first);
	ft_map2d(first);
	mlx_put_image_to_window(first->draw.init, first->draw.wdow, \
		first->draw.img, 0, 0);
	mlx_hook(first->draw.wdow, 2, (1L << 0), key_hook, first);
	mlx_loop(first->draw.init);
	return (0);
}
