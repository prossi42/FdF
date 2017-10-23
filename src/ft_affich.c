/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affich.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 00:55:02 by prossi            #+#    #+#             */
/*   Updated: 2017/09/07 10:02:18 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_affich_pars(t_first *first, int option)
{
	if (option == 0)
		ft_putendl(" xxxx Error in Parsing Process");
	if (option == 1)
	{
		ft_putendl(" ---> Ok ! So this is the Map...\n");
	}
}

void	ft_affich_pres(void)
{
	ft_putendl("\n\t\t Hi, Welcome aboard !\n\n");
}

void	ft_affich_first(t_first *first, int option)
{
	if (option == 0)
	{
		ft_putendl(" xxxx Usage : ./exec. + map");
		ft_putendl("\t |-> A valid one will be perfect :-)");
		ft_putendl("\t\t |-> Hint : Only ' ' & '\\n' & numbers (+/-) accepted");
	}
	if (option == 1)
		ft_affich_pres();
	if (option == 2)
		ft_putendl(" xxxx Error in Open Process");
	if (option == 3)
		ft_putendl(" xxxx Error in Read Process");
	if (option == 4)
		ft_putendl(" ---> Yeah ! This is a f****** valid map !");
}
