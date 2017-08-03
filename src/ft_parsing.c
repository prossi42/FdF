/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 23:01:46 by prossi            #+#    #+#             */
/*   Updated: 2017/08/02 23:01:47 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void    ft_count_point(t_main *main)
{
    int     i;
    int     x;
    int     y;

    i = 0;
    x = 0;
    y = 0;
    while (main->buf[i++])
    {
        if (main->buf[i] >= '0' && main->buf[i] <= '9')
            if (main->buf[i + 1] == ' ' || main->buf[i + 1] == '\n')
                x++;
        if (main->buf[i] == '\n')
        {
            if (x >= main->pars.x_max)
            {
                main->pars.x_max = x;
                x = 0;
            }
            y++;
        }
    }
    if (main->buf[i - 1] != '\n')
        y++;
    main->pars.y_max = y;
    ft_affich_pars(main, 1);
}

void     ft_get_number(t_main *main)
{
    char    **tabnl;
    char    **tabsp;
    int     i;
    int     j;
    int     k;

    i = 0;
    j = 0;
    k = 0;
    tabnl = NULL;
    tabnl = ft_strsplit(main->buf, '\n');
    while (tabnl[i])
    {
        tabsp = ft_strsplit(tabnl[i], ' ');
        while (tabsp[j])
        {
            main->pars.tabi[k][j] = ft_atoi(tabsp[j]);
            j++;
        }
        j = 0;
        k++;
        i++;
    }
}

int     ft_check_map(t_main *main)
{
    int     i;

    i = 0;
    if (main->buf[0] == '\0')
        return (-1);
    while (main->buf[i])
    {
        if (main->buf[i] < '0' || main->buf[i] > '9')
            if (main->buf[i] != ' ' && main->buf[i] != '\n' && main->buf[i] != '-')
                return (-1);
        if (main->buf[i] == '-' && main->buf[i + 1] == ' ')
            return (-1);
        i++;
    }
    return (0);
}

int     ft_parsing(t_main *main)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (ft_check_map(main) == -1)
        return (-1);
    ft_count_point(main);
    main->pars.tabi = ft_tabint(main->pars.x_max, main->pars.y_max);
    ft_get_number(main);
	ft_affich_main(main, 4);
    return (0);
}
