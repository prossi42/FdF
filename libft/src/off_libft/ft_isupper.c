/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 11:37:24 by prossi            #+#    #+#             */
/*   Updated: 2017/02/27 12:18:20 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include "../../include/off_libft/libft.h"

int		ft_isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}