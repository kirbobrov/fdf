/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:02:20 by kbobrov           #+#    #+#             */
/*   Updated: 2017/03/07 17:02:25 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_draw(int x0, int y0, int x1, int y1, int color, t_fdf *s) ///, t_point *p)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = x1 >= x0 ? 1 : -1;
	int sy = y1 >= y0 ? 1 : -1;

	if (dy <= dx)
	{
		int d = (dy << 1) - dx;
		int d1 = dy << 1;
		int d2 = (dy - dx) << 1;
		mlx_pixel_put (s->mlx, s->win, x0, y0, color);
		for(int x = x0 + sx, y = y0, i = 1; i <= dx; i++, x += sx) ///, color--)
		{
			if ( d >0)
			{
				d += d2;
				y += sy;

			}
			else
				d += d1;
			mlx_pixel_put (s->mlx, s->win, x, y, color);

		}
	}
	else
	{
		int d = (dx << 1) - dy;
		int d1 = dx << 1;
		int d2 = (dx - dy) << 1;
		mlx_pixel_put (s->mlx, s->win, x0, y0, color);
		for(int y = y0 + sy, x = x0, i = 1; i <= dy; i++, y += sy) ///, color--)
		{
			if ( d >0)
			{
				d += d2;
				x += sx;
			}
			else
				d += d1;
			mlx_pixel_put (s->mlx, s->win, x, y, color);
		}
	}
}

/*
int 	ft_bits(t_fdf *s, t_point **pt) ////// где то на битах происходит сигфолт
{
	int x;
	int y;

	s->ymax > s->xmax ? (s->mult = (800 / s->ymax)) : (s->mult = (800 / s->xmax));
	y = 0;
	while (y <= s->ymax)
	{
		x = 0;
		while (x < s->xmax)
		{
			//(pt[y][x].z == 0) ? (color = 0xFF0000) : (color = pt[y][x].color);
			if (x != s->xmax)
				mlx_pixel_put (s->mlx, s->win, ((pt[y][x].x - (s->xmax / 2)) * s->mult + 700),
							   ((pt[y][x].y - (s->ymax / 2)) * s->mult + 800), pt[y][x].color);
			if (y != s->ymax)
				mlx_pixel_put (s->mlx, s->win, ((pt[y][x].x - (s->xmax / 2)) * s->mult + 700),
							   ((pt[y][x].y - (s->ymax / 2)) * s->mult + 800), pt[y][x].color);

			x++;
		}

		y++;
	}
	return(0);
}*/

void	ft_image(t_fdf *s)
{
	int 	x;
	int 	y;
	double	mul;

	///printf("conner xa == %.2f  conner xa0 == %.2f \n", s->xa, s->xa0);
	///printf("conner ya == %.2f  conner ya0 == %.2f \n", s->ya, s->ya0);
	///printf("conner za == %.2f  conner za0 == %.2f \n", s->za, s->za0);
	///printf("dy == %i  \t\n", s->dx);
	///printf(" dx == %i \t\n", s->dy);
	///ft_isometric(s, s->pt);
	s->ymax > s->xmax ? (mul = (s->mult / s->ymax)) : (mul = (s->mult / s->xmax));
	y = 0;
	while (y < s->ymax)
	{
		x = 0;
		while (x < s->xmax)
		{
			if (s->pt[y][x].z0 > 0 && s->pt[y][x].color == ft_atoi_base("FFFFFF", 16))
				s->pt[y][x].color = ft_atoi_base("FF000F", 16);
			///(pt[y][x].z == 0) ? (color = 0xFF0000) : (color = pt[y][x].color);
			if (x != s->xmax - 1)
				ft_draw(((s->pt[y][x].x) * mul + s->dx),
						((s->pt[y][x].y) * mul + s->dy),
						((s->pt[y][x + 1].x) * mul + s->dx),
						((s->pt[y][x + 1].y) * mul + s->dy), s->pt[y][x].color, s);

			if (y != s->ymax - 1)
				ft_draw(((s->pt[y][x].x) * mul + s->dx),
						((s->pt[y][x].y) * mul + s->dy),
						((s->pt[y + 1][x].x) * mul + s->dx),
						((s->pt[y + 1][x].y) * mul + s->dy), s->pt[y][x].color, s);
			x++;
		}
		y++;
	}
}