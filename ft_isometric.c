/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isometric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbobrov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 14:00:46 by kbobrov           #+#    #+#             */
/*   Updated: 2017/03/12 14:00:48 by kbobrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_matrx(t_fdf *s, t_point *pt)
{
	double y;
	double z;
	double a;

	y = pt->y;
	z = pt->z;
	a = s->xa;

	RAD(a);
	//pt.x = (x * 1);
	pt->y = ((y * cos(a)) + (z * (-sin(a))));
	pt->z = ((y * sin(a)) + (z * cos(a)));
}

void	ft_matry(t_fdf *s, t_point *pt)
{
	double x;
	double z;
	double a;

	x = pt->x;
	z = pt->z;
	a = s->ya;

	RAD(a);
	pt->x = ((x * cos(a)) + (z * sin(a)));
	//pt.y = ((y * cos(a)) + (z * (-sin(a))));
	pt->z = ((x * (-sin(a))) + (z * cos(a)));
}

void	ft_matrz(t_fdf *s, t_point *pt)
{
	double x;
	double y;
	double a;

	a = s->za;
	//s->mult = 700;
	x = pt->x;
	y = pt->y;

	RAD(a);
	pt->x = ((x * cos(a)) + (y * (-sin(a))));
	pt->y = ((x * sin(a)) + (y * (cos(a))));
	//pt->z = ((x * (-sin(a))) + (z * cos(a)));
}

void	ft_begin_point(t_fdf *s)
{
	int y;
	int x;

	y = 0;
	while (y < s->ymax)
	{
		x = 0;
		while (x < s->xmax)
		{
			s->pt[y][x].x = s->pt[y][x].x0;
			s->pt[y][x].y = s->pt[y][x].y0;
			s->pt[y][x].z = s->pt[y][x].z0;
			x++;
		}
		y++;
	}
}

void	ft_isometric(t_fdf *s)///, t_point **pt)
{
	int 	x;
	int 	y;
	//double xa;
	//double ya;
	//double za;
	///double	mul;

	///	mul = 0;
	y = 0;
	s->xa = s->xa0;
	s->ya = s->ya0;
	s->za = s->za0;
	ft_begin_point(s);
	///s->ymax > s->xmax ? (mul = (s->mult / s->ymax)) : (mul = (s->mult / s->xmax));
	//printf("conner in isometric== %f  conner 0  in isometric== %f \n", s->xa, s->xa0);
	while (y < s->ymax)
	{
		x = 0;
		while (x < s->xmax)
		{
			///pt[y][x].x = pt[y][x].x * mul;
			///pt[y][x].y = pt[y][x].y * mul;
			ft_matrz(s, &s->pt[y][x]);
			ft_matrx(s, &s->pt[y][x]);
			ft_matry(s, &s->pt[y][x]);
			x++;
			//printf("x0 = %.f!\tx = %.f!\ty0 = %.f!\ty = %.f!\tz0 = %.f!\tz = %.f!\t\n", pt[y][x].x0, pt[y][x].x, pt[y][x].y0, pt[y][x].y, pt[y][x].z0, pt[y][x].z);
		}
		y++;
	}
}