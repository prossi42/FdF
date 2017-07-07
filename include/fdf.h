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
	void	*init;
	void	*wdow;
	char	*line;
	char	*buf;
	char	*num;
	int		fd;
	int		x_max;
	int		y_max;
	int		count;
	int		count_swap;
	int		**x_y;
	char	**ychar;
	char	**xchar;
	int		i_affich;
}					t_param;

int		ft_key_number(int keycode);
int		ft_parsing(t_param *param);
void 	ft_affich(t_param *param, float option);
void 	ft_count_xmax_ymax(t_param *param);
int 	ft_tab_x_y(t_param *param);
int		ft_init_struct(t_param *param);
int		ft_mlx(t_param *param);
int		ft_check_map(t_param *param);
int		ft_tab(t_param *param);
void 	ft_charjoinstr(t_param *param, char c);

#endif
