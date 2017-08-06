/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 03:11:29 by prossi            #+#    #+#             */
/*   Updated: 2017/08/02 19:22:48 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

	// Changer le path en # include <mlx.h> Dump 42
	// Changer le path en # include "../../../minilibx_macos/mlx.h"
	// Ajouter -lmlx makefile Dump 42
# include <mlx.h>
# include <stdio.h>
# include "../my_libft/include/off_libft/libft.h"
# include "../my_libft/include/pimp_libft/my_libft.h"

typedef struct		s_draw
{
	void			*init;
	void			*wdow;
	int				winsize_x;
	int				winsize_y;
	int				posx;
	int				posy;
	int				padx;
	int				pady;
}					t_draw;

typedef struct		s_pars
{
	int				x_max;
	int				y_max;
	int				**tabi;
	int				**tabposx;
	int				**tabposy;
}					t_pars;

typedef struct		s_first
{
	t_pars			pars;
	t_draw			draw;
	int				fd;
	char			*buf;
}					t_first;

void		ft_affich_first(t_first *first, int option);
void		ft_affich_draw(t_first *first, int option);
void		ft_affich_pars(t_first *first, int option);
void		ft_init_struct(t_first *first);
int			ft_parsing(t_first *first);
int			ft_mlx(t_first *first);
int			ft_key_number(int keycode);
// void		ft_map2d(t_first *first);
void 		ft_map3d(t_first *first);

#endif
