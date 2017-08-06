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

// #include "../include/fdf.h"
//
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
//
// void		ft_map2d(t_first *first)
// {
// 	int		x;
// 	int		y;
//
// 	x = 0;
// 	y = 0;
// 	while (y < (first->pars.y_max - 1))
// 	{
// 		while (x < first->pars.x_max)
// 		{
//     		mlx_pixel_put(first->draw.init, first->draw.wdow, first->pars.tabposx[y][x], first->pars.tabposy[y][x], 0xFFFFFF);
//     		if ((x + 1) != first->pars.x_max)
//                 ft_tracex(first, y, x);
//     		if ((y + 2) != first->pars.y_max)
//     			ft_tracey(first, y, x);
//     		x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// }
