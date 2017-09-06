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

void	ft_command_ctrl(void)
{
	ft_putstr("\n ---> This is your turn now !\n");
	ft_putstr("\n -------------------------------------------- ");
	ft_putstr("\n|                            ^               |");
	ft_putstr("\n|            You can move  <   >             |");
	ft_putstr("\n|                            v               |");
	ft_putstr("\n|       You can zoom with '/' & '*'          |");
	ft_putstr("\n|                                            |");
	ft_putstr("\n|  You can rotate...hum with 'a' & 'b'       |");
	ft_putstr("\n|                                            |");
	ft_putstr("\n|  You can inc. & dec. depth with '+' & '-'  |");
	ft_putstr("\n|                                            |");
	ft_putstr("\n|        You can reset with 'return'         |");
	ft_putstr("\n --------------------------------------------\n\n");
}

int		ft_reduce(t_first *first, char **argv)
{
	if ((first->fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_affich_first(first, 2);
		return (-1);
	}
	if (!(first->buf = ft_readfile(first->fd)))
	{
		ft_affich_first(first, 3);
		return (-1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_first		first;

	if (argc != 2)
	{
		ft_affich_first(&first, 0);
		return (-1);
	}
	ft_affich_first(&first, 1);
	ft_init_struct(&first, 1);
	if (ft_reduce(&first, argv) == -1)
		return (-1);
	if (ft_parsing(&first) == -1)
	{
		ft_affich_pars(&first, 0);
		return (-1);
	}
	ft_command_ctrl();
	ft_init_struct(&first, 2);
	if (ft_mlx(&first) == -1)
		return (-1);
	return (0);
}
