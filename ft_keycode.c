/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 14:32:52 by kbobrov           #+#    #+#             */
/*   Updated: 2017/03/25 14:32:55 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_destroy(t_fdf *s)
{
	///mlx_destroy_image(s->mlx, s->img);
	mlx_clear_window(s->mlx, s->win);
	ft_image(s);
}

int ft_rotate(int keycode, t_fdf *s)
{
	(keycode == 0) ? s->za0 += 10 : 0;
	(keycode == 6) ? s->za0 -= 10 : 0;
	(keycode == 1) ? s->xa0 += 10 : 0;
	(keycode == 7) ? s->xa0 -= 10 : 0;
	(keycode == 2) ? s->ya0 += 10 : 0;
	(keycode == 8) ? s->ya0 -= 10 : 0;
	if (keycode == 4)
	{
		s->xa0 = 48;
		s->ya0 = 0;
		s->za0 =  315;
	}
	ft_isometric(s);
	mlx_destroy(s);
	return (0);
}

int ft_move(int keycode, t_fdf *s)
{
	(keycode == 126) ? s->dy -= 100 : 0;
	(keycode == 125) ? s->dy += 100 : 0;
	(keycode == 123) ? s->dx -= 100 : 0;
	(keycode == 124) ? s->dx += 100 : 0;
	mlx_destroy(s);
	return (0);
}

int ft_zoom(int keycode, t_fdf *s)
{
	(keycode == 78 || keycode == 27) ? s->mult -= 100 : 0;
	(keycode == 69 || keycode == 24) ? s->mult += 100 : 0;
	(keycode == 45) ? s->mult = 700 : 0;
	(keycode == 45) ? s->mult = 700 : 0;
	mlx_destroy(s);
	return (0);
}

int	my_key(int	keycode, t_fdf *s)
{
	(keycode == 53) ? exit (53) : 0;
	(keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123) ? ft_move(keycode, s) : 0;
	(keycode == 78 || keycode == 27 || keycode == 69 || keycode == 24 || keycode == 45) ? ft_zoom(keycode, s) : 0;
	(keycode == 0 || keycode == 6 || keycode ==  1 || keycode == 7 || keycode == 2 || keycode == 8 || keycode == 4) ? ft_rotate(keycode, s) : 0;
	printf ("my keycode %d\n", keycode);
	return (0);
}
