/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 12:33:09 by prossi            #+#    #+#             */
/*   Updated: 2017/07/11 03:55:52 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void    ft_count_map(t_param *param)
{
    int     i;
    int     nb;
    int     j;

    i = 0;
    nb = 0;
    j = 0;
    while (param->buf[i])
    {
        while (param->buf[i] >= '0' && param->buf[i] <= '9')
            i++;
        if (param->buf[i - 1] && param->buf[i - 1] >= '0' && param->buf[i - 1] <= '9')
            nb++;
        if (param->buf[i] == '\n')
        {
            j++;
            if (nb >= param->x_max)
            {
                param->x_max = nb;
                nb = 0;
            }
        }
        i++;
    }
    param->y_max = j;
}

// int 	ft_replace_char(t_param *param)
// {
//     int     i;
//
//     i = 0;
//     while (param->buf[i])
//     {
//         if (param->buf[i] < '0' || param->buf[i] > '9')
//         {
//             if (param->buf[i] != '\n')
//                 if (param->buf[i] != '-' && param->buf[i + 1])
//                     if (param->buf[i + 1] < '0' || param->buf[i + 1] > '9')
//                         param->buf[i] = ' ';
//         }
//         i++;
//     }
//     return (0);
// }
int     ft_check_map(t_param *param)
{
    int     i;
    int     k;

    i = 0;
    k = 0;
    while (param->buf[i])
    {
        if (param->buf[i] != '\n' && param->buf[i] != ' ' && param->buf[i] != '-')
        {
            if (param->buf[i] >= '0' && param->buf[i] <= '9')
                k++;
            else
                return (-1);
        }
        i++;
    }
    if (k == 0)
        return (-1);
    // if (ft_replace_char(param) == -1)
    //     return (-1);
    ft_count_map(param);
    return (0);
}
