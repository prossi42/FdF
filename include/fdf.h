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

# include <mlx.h>
# include "../my_libft/include/off_libft/libft.h"
# include "../my_libft/include/pimp_libft/my_libft.h"

typedef struct		s_param
{
	char	*buf;
	char	*num;
	int		fd;
	int		x_max;
	int		y_max;
	int		x;
	int		**x_y;
	char	**ychar;
	char	**xchar;
	int		i_affich;
}					t_param;

typedef struct		s_mlx
{
	void 	*init;
	void 	*wdow;
	int		x_pixel;
	int		y_pixel;
}					t_mlx;
int		ft_key_number(int keycode);
int		ft_parsing(t_param *param);
void 	ft_affich(t_param *param, float option);
int 	ft_tab_x_y(t_param *param);
int		ft_init_struct(t_param *param);
int		ft_mlx(t_param *param);
int		ft_check_map(t_param *param);
int		ft_tab(t_param *param);
void 	ft_charjoinstr(t_param *param, char c);

#endif
