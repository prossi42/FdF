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

int 	ft_parsing(t_param *param)
{
    int     i;

    i = 0;
    param->buf= ft_readfile(param->fd);
    ft_count_xmax_ymax(param);
    ft_tab_x_y(param);
    ft_affich(param, 0);
    param->num = ft_strnew(1);
    while (param->buf[i] != '\n')
    {
        if (param->buf[i] >= '0' && param->buf[i] <= '9')
        {
            ft_charjoinstr(param, param->buf[i]);
            i++;
        }
        else
          i++;

    }
    ft_putstr(param->num);
    // param->ychar = ft_strsplit(param->buf, '\n');
    // while (param->ychar[y])
    // {
    //     param->xchar = ft_strsplit(param->ychar[y], ' ');
    //     while (param->xchar[x])
    //     {
    //       ft_putstr(" ---> Voici le chiffre [");
    //       ft_putstr(param->xchar[x]);
    //       ft_putendl("]");
    //         // param->x_y =
    //         x++;
    //     }
    //     y++;
    // }
    return (0);
}
