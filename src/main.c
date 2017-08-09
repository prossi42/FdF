/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 12:46:48 by prossi            #+#    #+#             */
/*   Updated: 2017/08/06 12:46:51 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			main(int argc, char **argv)
{
	t_first		first;

	if (argc != 2)
	{
		ft_affich_first(&first, 0);
		return (-1);
	}
	ft_affich_first(&first, 1);
	ft_init_struct(&first, 1);
	if ((first.fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_affich_first(&first, 2);
		return (-1);
	}
	if (!(first.buf = ft_readfile(first.fd)))
	{
		ft_affich_first(&first, 3);
		return (-1);
	}
	if (ft_parsing(&first) == -1)
	{
		ft_affich_pars(&first, 0);
		return (-1);
	}
	ft_init_struct(&first, 2);
	if (ft_mlx(&first) == -1)
	{
		return (-1);
	}
	close(first.fd);
	return (0);
}
