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
		ft_affich(&param, 2);
		return (-1);
	}
	if ((param.fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_affich(&param, 3);
		return (-1);
	}
	if (!(param.buf = ft_readfile(param.fd)))
	{
		ft_affich(&param, 4);
		return (-1);
	}
	if (ft_parsing(&param) == -1)
	{
		ft_affich(&param, 7);
		return (-1);
	}
    ft_affich(&param, 0);
	if (ft_mlx(&param) != 0)
	{
		ft_putendl("Erreur Fonctions mlx -> ft_mlx");
		return (-1);
	}
	return (0);
}
