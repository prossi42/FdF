/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_x_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 11:51:29 by prossi            #+#    #+#             */
/*   Updated: 2017/06/28 11:51:32 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int    ft_tab_x_y(t_param *param)
{
    int     i;

    i = 0;
    if (!(param->x_y = (int **)malloc(sizeof(int *) * param->y_max)))
        return (-1);
    while (i < param->y_max)
    {
        if(!(param->x_y[i] = (int *)malloc(sizeof(int) * param->x_max)))
            return (-1);
        i++;
    }
    return (0);
}
