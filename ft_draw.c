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

void	img_put(t_fdf *s, int x, int y, int sizel, char *buff, t_color *color)
{
	int pix;

///	printf("x:%d y %d\n", x,y);
	if (y >= 0 && x >= 0 && y < HEIGHT  && x < WEIGHT)
	{
		pix = y * sizel + x * 4;
		if (pix < WEIGHT * HEIGHT * 4)
		{
			buff[pix] = color->blue; ///0x0FF;//color->r;
			buff[pix + 1] = color->green; ///0x0FF;//color->g;
			buff[pix + 2] = color->red;//0x0FF;//color->b;
		}
	}
}

void ft_draw(int x0, int y0, int x1, int y1, t_fdf *s, t_color *color)///	, int size, char *buff) ///, t_point *p)
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
		img_put(s, x0, y0, s->sizel, s->buf, color);
		for(int x = x0 + sx, y = y0, i = 1; i <= dx; i++, x += sx) ///, color--)
		{
			if ( d >0)
			{
				d += d2;
				y += sy;

			}
			else
				d += d1;
			img_put(s, x, y, s->sizel, s->buf, color);
		}
	}
	else
	{
		int d = (dx << 1) - dy;
		int d1 = dx << 1;
		int d2 = (dx - dy) << 1;
		img_put(s, x0, y0, s->sizel, s->buf, color);
		//mlx_pixel_put (s->mlx, s->win, x0, y0, color);
		for(int y = y0 + sy, x = x0, i = 1; i <= dy; i++, y += sy) ///, color--)
		{
			if ( d >0)
			{
				d += d2;
				x += sx;
			}
			else
				d += d1;
			img_put(s, x, y, s->sizel, s->buf, color);
			//mlx_pixel_put (s->mlx, s->win, x, y, color);
		}
	}
}

void	ft_image(t_fdf *s)
{
	int 	x;
	int 	y;
	double	mul;
	///int bpp;
	///int ednl;
	///int sizel;

	s->bpp = 0;
	s->endl = 0;
	s->sizel = 0;
	///char *buff;
	///printf("dy == %i  \t\n", s->dx);
	///printf(" dx == %i \t\n", s->dy);
	///ft_isometric(s, s->pt);
	s->img = mlx_new_image(s->mlx, WEIGHT, HEIGHT);
	s->buf = mlx_get_data_addr(s->img, &s->bpp, &s->sizel, &s->endl);
	s->ymax > s->xmax ? (mul = (s->mult / s->ymax)) : (mul = (s->mult / s->xmax));
	y = 0;
	while (y < s->ymax)
	{
		x = 0;
		while (x < s->xmax)
		{
			///if (s->pt[y][x].z0 > 0 && s->pt[y][x].color == ft_atoi_base("FFFFFF", 16))
				///s->pt[y][x].color = ft_atoi_base("FF000F", 16);
			///(pt[y][x].z == 0) ? (color = 0xFF0000) : (color = pt[y][x].color);
			if (x != s->xmax - 1)
				ft_draw(((s->pt[y][x].x) * mul + s->dx),
						((s->pt[y][x].y) * mul + s->dy),
						((s->pt[y][x + 1].x) * mul + s->dx),
						((s->pt[y][x + 1].y) * mul + s->dy), s, s->pt[y][x].col);/// s->sizel, s->buf);

			if (y != s->ymax - 1)
				ft_draw(((s->pt[y][x].x) * mul + s->dx),
						((s->pt[y][x].y) * mul + s->dy),
						((s->pt[y + 1][x].x) * mul + s->dx),
						((s->pt[y + 1][x].y) * mul + s->dy), s, s->pt[y][x].col);///, s->sizel, s->buf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
}