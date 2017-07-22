/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 22:14:34 by prossi            #+#    #+#             */
/*   Updated: 2017/06/15 22:16:45 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int         ft_init_struct2(t_mlx *mlx, t_param *param )
{
            // Variables de la Minilibx
    mlx->wdow = NULL;
    mlx->win_size_x = 1500;
    mlx->win_size_y = 750;
    mlx->posx = (mlx->win_size_x / 15);
    mlx->posy = (mlx->win_size_y / 7);
    mlx->padding_x = (mlx->posx / 2);
    mlx->padding_y = (mlx->posy / 2);
    return (0);
}

int			ft_init_struct(t_param *param)
{
            // Variables du PARSING
    param->fd = 0;
    param->i_affich = 0;
    param->x_max = 0;
    param->y_max = 0;
    param->x = 0;
    param->buf = NULL;
    param->x_y = 0;
    param->x_ychar = NULL;
    param->num = NULL;
    return (0);
}
