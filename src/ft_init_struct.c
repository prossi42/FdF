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

int			ft_init_struct(t_param *param)
{
    param->wdow = NULL;
    param->line = NULL;
    param->buf = NULL;
    param->fd = 0;
    param->i_affich = 0;
    param->count = 0;
    param->count_swap = 0;
    param->x_max = 0;
    param->y_max = 0;
    param->x_y = NULL;
    param->ychar = NULL;
    param->xchar = NULL;
    param->num = NULL;
    return (0);
}
