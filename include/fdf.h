/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 03:11:29 by prossi            #+#    #+#             */
/*   Updated: 2017/06/03 03:18:06 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

	// Changer le path en # include <mlx.h> Dump 42
# include "../../../minilibx_macos/mlx.h"
# include <stdio.h>
# include "../my_libft/include/off_libft/libft.h"
# include "../my_libft/include/pimp_libft/my_libft.h"

typedef struct		s_draw
{

}					t_draw;

typedef struct		s_pars
{
	int			x_max;
	int			y_max;
	int			**tabi;
}					t_pars;

typedef struct		s_main
{
	t_pars		pars;
	t_draw		draw;
	int			fd;
	char		*buf;
}					t_main;

void		ft_affich_main(t_main *main, int option);
void		ft_affich_draw(t_main *main, int option);
void		ft_affich_pars(t_main *main, int option);
void		ft_init_struct(t_main *main);
int			ft_parsing(t_main *main);

#endif
