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

void		ft_init_struct(t_first *first)
{
    first->fd = 0;
    first->pars.x_max = 0;
    first->pars.y_max = 0;
    first->buf = NULL;
    first->draw.winsize_x = 2500;
    first->draw.winsize_y = 1200;
    first->draw.posx = (first->draw.winsize_x) / 9;
    first->draw.posy = (first->draw.winsize_y) / 4;
    first->draw.padx = (first->draw.winsize_x) / 200;
    first->draw.pady = (first->draw.winsize_y) / 200;
    first->draw.prof = 10;
    first->draw.rot = 0;
}
