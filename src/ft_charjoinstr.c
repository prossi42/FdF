/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoinstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 03:24:10 by prossi            #+#    #+#             */
/*   Updated: 2017/07/07 03:25:19 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		ft_charjoinstr(t_param *param, char c)
{
    int     i;

    i = 0;
    param->num = ft_realloc_free(param->num, 1);
    while (param->num[i])
      i++;
    param->num[i] = c;
    param->num[i + 1] = '\0';
}
