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

int			key_hook(int keycode, t_param *param)
{
	int		letter;

	letter = ft_key_number(keycode);
	// if (letter == -1)
	// 	ft_putendl("Only low Alphab. char.");
	return (0);
}

int			ft_mlx(t_param *param)
{
    param->init = mlx_init();
    param->wdow = mlx_new_window(param->init, 1200, 1200, "1st Window");
    mlx_key_hook(param->wdow, key_hook, &param);
    mlx_string_put(param->init, param->wdow, 500, 200, 0xFFFFFF, "Bonjour !");
//	mlx_pixel_put(param.init, param.wdow, )
	mlx_loop(param->init);
    return (0);
}
