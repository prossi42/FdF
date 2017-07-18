/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 03:08:04 by prossi            #+#    #+#             */
/*   Updated: 2017/06/03 03:15:52 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void    ft_putintab(t_param *param, int y)
{
    int         stock;

    stock = 0;
    stock = ft_atoi(param->num);
    param->x_y[y][param->x] = stock;
    param->x++;
    if (param->x == param->x_max)
        param->x = 0;

}

int     ft_get_number(t_param *param)
{
    int        y;
    int        x;

    y = 0;
    x = 0;
    param->ychar = ft_strsplit(param->buf, '\n');
    while (param->ychar[y])
    {
        while (param->ychar[y][x])
        {
            while (param->ychar[y][x] == ' ')
                x++;
            if (!param->num)
                param->num = ft_strnew(1);
            while (param->ychar[y][x] >= '0' && param->ychar[y][x] <= '9')
            {
                if (param->ychar[y][x - 1] == '-')
                    ft_charjoinstr(param, param->ychar[y][x - 1]);
                ft_charjoinstr(param, param->ychar[y][x]);
                x++;
            }
            ft_putintab(param, y);
            ft_bzero(param->num, ft_strlen(param->num));
        }
        y++;
        x = 0;
    }
    return (0);
}

int     ft_reduc_ft(t_param *param)
{
    if (ft_check_map(param) == -1)
        return (-1);
    ft_affich(param, 5);
    ft_tab_x_y(param);
    if (ft_get_number(param) == -1)
        return (-1);
    return (0);
}

int 	ft_parsing(t_param *param)
{
    if (ft_reduc_ft(param) == -1)
        return (-1);
    return (0);
}
