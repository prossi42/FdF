/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 03:09:27 by prossi            #+#    #+#             */
/*   Updated: 2017/06/03 03:19:48 by prossi           ###   ########.fr       */
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
	// if (keycode == 36)
	// 	return (-2);
	if (keycode == 0)
		return (97);
	if (keycode == 11)
		return (98);
	if (keycode == 8)
		return (99);
	if (keycode == 2)
		return (100);
	if (keycode == 14)
		return (101);
	if (keycode == 3)
		return (102);
	if (keycode == 5)
		return (103);
	if (keycode == 4)
		return (104);
	if (keycode == 34)
		return (105);
	if (keycode == 38)
		return (106);
	if (keycode == 40)
		return (107);
	if (keycode == 37)
		return (108);
	if (keycode == 46)
		return (109);
	if (keycode == 45)
		return (110);
	if (keycode == 31)
		return (111);
	if (keycode == 35)
		return (112);
	if (keycode == 12)
		return (113);
	if (keycode == 15)
		return (114);
	if (keycode == 1)
		return (115);
	if (keycode == 17)
		return (116);
	if (keycode == 32)
		return (117);
	if (keycode == 9)
		return (118);
	if (keycode == 13)
		return (119);
	if (keycode == 7)
		return (120);
	if (keycode == 16)
		return (121);
	if (keycode == 6)
		return (122);
	return (-1);
}
