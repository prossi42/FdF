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

void	ft_count_point(t_first *first, int i)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (first->buf[i++])
	{
		if (first->buf[i] >= '0' && first->buf[i] <= '9')
			if (first->buf[i + 1] == ' ' || first->buf[i + 1] == '\n')
				x++;
		if (first->buf[i] == '\n')
		{
			if (x >= first->pars.x_max)
			{
				first->pars.x_max = x;
				x = 0;
			}
			y++;
		}
	}
	if (first->buf[i - 1] != '\n')
		y++;
	first->pars.y_max = y;
	ft_affich_pars(first, 1);
}

void	ft_get_number(t_first *first)
{
	char	**tabnl;
	char	**tabsp;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	tabnl = NULL;
	tabnl = ft_strsplit(first->buf, '\n');
	while (tabnl[i])
	{
		tabsp = ft_strsplit(tabnl[i], ' ');
		while (tabsp[j])
		{
			first->pars.tabi[k][j] = ft_atoi(tabsp[j]);
			j++;
		}
		j = 0;
		k++;
		i++;
	}
}

int		ft_check_map(t_first *first)
{
	int		i;

	i = 0;
	if (first->buf[0] == '\0')
		return (-1);
	while (first->buf[i])
	{
		if (first->buf[i] < '0' || first->buf[i] > '9')
			if (first->buf[i] != ' ' && first->buf[i] != '\n' && \
			first->buf[i] != '-')
				return (-1);
		if (first->buf[i] == '-' && first->buf[i + 1] == ' ')
			return (-1);
		i++;
	}
	return (0);
}

int		ft_parsing(t_first *first)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_check_map(first) == -1)
		return (-1);
	ft_count_point(first, i);
	first->pars.tabi = ft_tabint(first->pars.x_max, first->pars.y_max);
	first->pars.tabposx = ft_tabint(first->pars.x_max, first->pars.y_max);
	first->pars.tabposy = ft_tabint(first->pars.x_max, first->pars.y_max);
	ft_get_number(first);
	ft_affich_first(first, 4);
	return (0);
}
