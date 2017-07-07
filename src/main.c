/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:26:49 by prossi            #+#    #+#             */
/*   Updated: 2017/06/03 03:19:50 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

int			main(int argc, char **argv)
{
	t_param		param;
	int			i;
	int			ret;


	i = 0;
	ret = 0;
	if (argc != 2)
	{
		ft_affich(&param, 1);
		return (-1);
	}
	if (ft_init_struct(&param) != 0)
	{
		ft_affich(&param, 6);
		return (-1);
	}
	if ((param.fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_affich(&param, 7);
		return (-1);
	}
	while ((ret = get_next_line(param.fd, &param.line) > 0))
	{
		i++;
		if (ft_check_map(&param) == 1)
		{
			ft_affich(&param, 3);
			return (-1);
		}
		param.count_swap = param.count;
		param.count = 0;

	}
	if (i == 0)
	{
		ft_affich(&param, 3);
		return (-1);
	}
	else
		close(param.fd);
		ft_affich(&param, 4);
		if ((param.fd = open(argv[1], O_RDONLY)) == -1)
		{
			ft_affich(&param, 7.1);
			return (-1);
		}
		if (ft_parsing(&param) == -1)
		{
			ft_putendl("Erreur Parsing -> ft_parsing");
			return (-1);
		}
	// if (ft_tab(param) == -1)
	// {
	// 	ft_affich(param, 5);
	// }
	// if (ft_mlx(&param) != 0)
	// {
	// 	ft_putendl("Erreur Fonctions mlx -> ft_mlx");
	// 	return (-1);
	// }
	return (0);
}
