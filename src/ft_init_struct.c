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

void	ft_init_struct(t_first *first, int option)
{
	if (option == 1)
	{
		first->fd = 0;
		first->pars.x_max = 0;
		first->pars.y_max = 0;
		first->buf = NULL;
	}
	if (option == 2)
	{
		first->draw.x = 50;
		first->draw.y = 20;
		first->draw.posx = first->draw.x;
		first->draw.posy = first->draw.y;
		first->draw.padx = ((WINSIZE_X) / first->pars.x_max);
		first->draw.pady = ((WINSIZE_X) / first->pars.x_max);
		first->draw.prof = 10;
		first->draw.rot = 0;
	}
	if (option == 3)
	{
		first->draw.posx = first->draw.x;
		first->draw.posy = first->draw.y;
		first->draw.padx = ((WINSIZE_X) / first->pars.x_max) + first->draw.zoom;
		first->draw.pady = ((WINSIZE_X) / first->pars.x_max) + first->draw.zoom;
	}
}
