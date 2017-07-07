/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affich.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 00:55:02 by prossi            #+#    #+#             */
/*   Updated: 2017/06/09 00:55:08 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void    ft_affich(t_param *param, float option)
{
    if (option == 0)
    {
        if (param->i_affich == 0)
        {
            param->i_affich = 1;
            ft_putchar('\n');
            ft_putendl("         RESULTATS DU PARSING\n");
            ft_putstr(" ---> Valeur max en x : [");
            ft_putnbr(param->x_max);
            ft_putendl("]");
            ft_putstr(" ---> Valeur max en y : [");
            ft_putnbr(param->y_max);
            ft_putendl("]\n");
        }
    }
    if (option == 1)
    {
        ft_putendl("Usage : ./exec. + map");
        ft_putendl("Si possible une valide :-)");
    }
    if (option == 2)
        ft_putendl(" xxxx Erreur lors du Malloc -> ft_tab_x_y");
    if (option == 3)
        ft_putendl("\n xxxx Map invalide");
    if (option == 4)
        ft_putendl("\n ---> Map valide");
    if (option == 5)
        ft_putendl(" xxxx Erreur lors du Malloc -> ft_tab");
    if (option == 6)
        ft_putendl(" xxxx Erreur Init. structure -> ft_init_struct");
    if (option == 7)
        ft_putendl(" xxxx Erreur open process -> main");
    if (option == 7.1)
        ft_putendl(" xxxx Erreur open process -> ft_parsing");
}
