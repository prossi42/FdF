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

int         ft_init_struct2(t_mlx *mlx)
{
            // Variables de la Minilibx
    mlx->wdow = NULL;
    mlx->buf = NULL;
    mlx->x_pixel = 0;
    mlx->y_pixel = 0;
}

int			ft_init_struct(t_param *param)
{
            // Variables du PARSING
    param->fd = 0;
    param->i_affich = 0;
    param->x_max = 0;
    param->y_max = 0;
    param->x = 0;
    param->x_y = NULL;
    param->ychar = NULL;
    param->xchar = NULL;
    param->num = NULL;

    return (0);
}
