/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 22:58:21 by prossi            #+#    #+#             */
/*   Updated: 2017/08/02 22:58:42 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			ft_key_number(int keycode)
{
	if (keycode == 53)
	{
		ft_putstr("\n	End Of Program");
		exit(-1);
	}
	if (keycode == 0)
		return (97);
	if (keycode == 11)
		return (98);
	return (-1);
}
