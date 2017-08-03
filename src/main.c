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

int			main(int argc, char **argv)
{
	t_main		main;

	if (argc != 2)
	{
		ft_affich_main(&main, 0);
		return (-1);
	}
	ft_affich_main(&main, 1);
	ft_init_struct(&main);
	if ((main.fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_affich_main(&main, 2);
		return (-1);
	}
	if (!(main.buf = ft_readfile(main.fd)))
	{
		ft_affich_main(&main, 3);
		return (-1);
	}
	if (ft_parsing(&main) == -1)
	{
		ft_affich_pars(&main, 0);
		return (-1);
	}
	if (ft_mlx(&main) == -1)
	{
		return (-1);
	}
	close(main.fd);
	return (0);
}
