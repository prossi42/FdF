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

void		ft_init_struct(t_main *main)
{
    main->fd = 0;
    main->pars.x_max = 0;
    main->pars.y_max = 0;
    main->buf = NULL;
    main->draw.winsize_x = 1800;
    main->draw.winsize_y = 900;
    main->draw.posx = (main->draw.winsize_x) / 10;
    main->draw.posy = (main->draw.winsize_y) / 10;
    main->draw.padx = (main->draw.winsize_x) / 50;
    main->draw.pady = (main->draw.winsize_y) / 20;
    main->draw.dx = 0;
    main->draw.dy = 0;
}
