/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 12:33:09 by prossi            #+#    #+#             */
/*   Updated: 2017/07/07 00:07:56 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void     ft_count_number(t_param *param)
{
    int     i;

    i = 0;
    while (param->line[i])
    {
        if (param->line[i] >= '0' && param->line[i] <= '9')
        {
            param->count++;
            if (param->line[i + 1])
                if (param->line[i + 1] >= '0' && param->line[i + 1] <= '9')
                    i++;
        }
        i++;
    }
}

int     ft_check_map(t_param *param)
{
    int     i;

    i = 0;
    if (param->line[i] == '\0')
        return (1);
    while (param->line[i])
    {
        if (param->line[i] < '0' || param->line[i] > '9')
        {
            if (param->line[i] != ' ' && param->line[i] != '\n')
                return (1);
            if (param->line[i] == '\n')
                if (param->line[i + 1] == '\n')
                    return (1);
            i++;
        }
        i++;
    }
    ft_count_number(param);
    if (param->count < param->count_swap)
      return (1);
    return (0);
}
