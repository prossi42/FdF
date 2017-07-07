/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_xmax_ymax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 05:44:20 by prossi            #+#    #+#             */
/*   Updated: 2017/06/09 05:44:23 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void 	ft_count_xmax_ymax(t_param *param)
{
    int     i;
    int     k;

    i = 0;
    k = 0;
    param->x_max = 0;
    param->y_max = 0;
    while (param->buf[i])
    {
        k++;
        if (param->buf[i] == '\n')
        {
            param->y_max++;
            if (k > param->x_max)
            {
                param->x_max = k;
            }
            k = 0;
        }
        i++;
    }
    if (param->x_max != 0)
        param->x_max--;
}
