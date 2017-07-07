/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 11:53:49 by prossi            #+#    #+#             */
/*   Updated: 2017/06/28 11:56:55 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			ft_tab(t_param *param)
{
	int		i;

	i = 0;
	if (!(param->ychar = (char **)malloc(sizeof(char *) * param->y_max)))
		return (-1);
	while (i < param->y_max)
	{
		if (!(param->ychar[i] = (char *)malloc(sizeof(char) * param->x_max)))
			return (-1);
		i++;
	}
	param->ychar[param->y_max] = NULL;
	return (0);
}
